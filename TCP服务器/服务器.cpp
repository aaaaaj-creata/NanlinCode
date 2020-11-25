#include<WinSock2.h>
#include<WS2tcpip.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

#pragma comment (lib,"ws2_32.lib")

#define DEF_PORT 27015
#define DEF_SIZE 512


int main()
{
	WSADATA wsaData;
	int iResult;
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET AcceptSocket = INVALID_SOCKET;


	//1.初始化
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error :%d\n", iResult);
		return 1;
	}

	//2.创建用于监听的套接字
	ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	if (ListenSocket == INVALID_SOCKET) {
		printf("create ListenSocket failed with error:%d\n", GetLastError());
		WSACleanup();
		return 1;
	}
	//3.为监听套接字绑定地址和端口号
	sockaddr_in addServer;

	addServer.sin_family = AF_INET;
	addServer.sin_port = htons(DEF_PORT);//
	addServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//

	iResult = bind(ListenSocket, (const sockaddr*)& addServer, sizeof(addServer));
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error:%d", GetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	//监听套接字
	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("Listen failed with error:%d\n", GetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	printf("TCP Server is starting...\n");

	sockaddr_in addClient;
	int addClient_Size = sizeof(addClient);
	char recvbuf[DEF_SIZE] = { 0 };
	int  recvlen = sizeof(recvbuf);
	//循环等待客户请求建立连接，并处理连接请求
	while (true) {
		AcceptSocket = accept(ListenSocket, (sockaddr*)& addClient, &addClient_Size);

		if (AcceptSocket == INVALID_SOCKET) {
			printf("accpet failed!\n");
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}
		printf("收到新的连接：%s\n", inet_ntoa(addClient.sin_addr));
		//循环接收数据
		while (true) {
			memset(recvbuf, 0, sizeof(recvbuf));
			iResult = recv(AcceptSocket, recvbuf, recvlen, 0);
			if (iResult > 0) {
				printf("数据内容: %s\n", recvbuf);
				continue;
			}
			else if (iResult == 0) {		
				printf("客户端已经正常关闭....\n");
				closesocket(AcceptSocket);
				break;
			}
			else {	//接收出现错误
				printf("recv failed with error: %d\n", GetLastError());
				closesocket(AcceptSocket);
				closesocket(ListenSocket);
				WSACleanup();
				return 1;
			}
		}
	}
	closesocket(AcceptSocket);
	closesocket(ListenSocket);
	WSACleanup();
	system("pause");
	return 0;
}
