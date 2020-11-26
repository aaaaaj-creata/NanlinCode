#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
// 连接到WinSock 2对应的lib文件：Ws2_32.lib, Mswsock.lib, Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
// 定义默认的缓冲区长度和端口号
#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "27015"

#pragma warning(disable:4996)

int __cdecl main(int argc, char** argv)
{
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo* result = NULL, * ptr = NULL, hints;
	char sendbuf[DEFAULT_BUFLEN];
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;
	char servIP[50] = "127.0.0.1";		// 保存输入的服务器IP

	// 初始化套接字
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	while (true)
	{
		printf("请输入服务器域名/IP地址：\n>>>");
		fflush(stdout);
		rewind(stdin);							// 清空缓冲区
		scanf_s("%s", servIP, 49);				// 输入服务器IP/域名
		// 解析服务器地址和端口号
		iResult = getaddrinfo(servIP, DEFAULT_PORT, &hints, &result);
		if (iResult != 0) {
			printf("getaddrinfo failed with error: %d\n", iResult);
			fflush(stdout);
			continue;
			//WSACleanup();
			//return 1;
		}
		for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
			// 创建套接字
			ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (ConnectSocket == INVALID_SOCKET) {
				printf("socket failed with error: %ld\n", WSAGetLastError());
				WSACleanup();
				return 1;
			}
			// 向服务器请求连接
			iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				ConnectSocket = INVALID_SOCKET;
				continue;
			}
			break;
		}
		break;
	}
	freeaddrinfo(result);
	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}
	printf(">>>连接到服务器(%s)...\n>>>连接成功...[ok]\n", servIP);
	struct sockaddr_in sa;			// 客户端ip
	int len = sizeof(sa);
	if (!getsockname(ConnectSocket, (struct sockaddr*) & sa, &len))
	{
		printf("Client Ip：%s   ", inet_ntoa(sa.sin_addr));
		printf("Client Port：%d \n\n", ntohs(sa.sin_port));
	}
	printf("max send: %d bites\n", DEFAULT_BUFLEN);
	printf("====================================================\n");
	char buff[40] = "";
	sprintf(buff, "title client:[%s: %d]", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
	system(buff);			// 设置客户端标题
	// 发送数据
	bool flag = true;
	while (flag)
	{
		printf("@[%s] send: >>> ", servIP);
		fflush(stdout);
		rewind(stdin);		// 清空输入缓冲区
					/* 这里空出头部字段 */
		if (0 == scanf_s("%[^\n]", sendbuf + sizeof(int), DEFAULT_BUFLEN - sizeof(int) - 1))		// 键盘输入数据
		{
			printf("\ninput error: 输入错误（tips：最多发送 %d 字节数据） \n", DEFAULT_BUFLEN - sizeof(int) - 1);
			continue;
		}
		int len = strlen(sendbuf + sizeof(int)) + sizeof(int);
		// 发送格式   长度(4bit)+数据
		memcpy(sendbuf, &len, sizeof(int));		// 写入头部信息
		if (0 == strncmp(sendbuf, "end", 3))	// 输入end 结束发送
		{
			// 数据发送结束，调用shutdown()函数声明不再发送数据，此时客户端仍可以接收数据
			iResult = shutdown(ConnectSocket, SD_SEND);
			if (iResult == SOCKET_ERROR) {
				printf("shutdown failed with error: %d\n", WSAGetLastError());
				closesocket(ConnectSocket);
				WSACleanup();
				return 1;
			}
			flag = false;
		}
		else
		{
			iResult = send(ConnectSocket, sendbuf, len, 0);
			if (iResult == SOCKET_ERROR) {
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(ConnectSocket);
				WSACleanup();
				return 1;
			}
			printf("|<--- (Sent size: %ld)\n|-------------------- \n", len);
		}

		// 接收服务器回复
		// 由于服务器统一回复3字节，这里不用循环接收
		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0)
			printf("|---> (recv size: %d ) \n\n", iResult);
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed with error: %d\n", WSAGetLastError());

	}
	// 关闭套接字
	closesocket(ConnectSocket);
	// 释放资源
	WSACleanup();
	return 0;
}

