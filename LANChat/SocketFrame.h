#pragma once
#pragma once  
#include "winsock2.h"
#include "stdio.h"
#pragma comment(lib,"ws2_32.lib")
//定义网络框架程序中所需的宏
#define TRUE			1
#define FALSE			0
#define	MAXLINE		    200	    // max text line length 
#define	DEFAULT_NAMELEN 100 //默认的名字长度

typedef struct tagTCPHDR		//TCP首部定义
{
	USHORT  sport;            //Source port 
	USHORT  dport;            //Destination port 
	ULONG   seq;              //Sequence number 
	ULONG   ack;              //Ack number 
	BYTE    hlen;             // TCP header len (num of bytes << 2) 
	BYTE    flags;            // Option flags 
	USHORT  window;           // Flow control credit (num of bytes) 
	USHORT  check;            // Checksum 
	USHORT  urgent;           // Urgent data pointer 
} TCPHDR, * PTCPHDR;
//TCP标志字段定义
#define TFIN        0x01    // Option flags: no more data 
#define TSYN        0x02    // sync sequence nums 
#define TRST        0x04    // reset connection 
#define TPUSH       0x08    // push buffered data 
#define TACK        0x10    // acknowledgement 
#define TURGE       0x20    // urgent 

//类框架中要实现的成员函数
class CSocketFrame
{
public:
	CSocketFrame(void); //构造函数
	~CSocketFrame(void); //析构函数
	int set_address(char* hname, char* sname, struct sockaddr_in* sap, char* protocol);
	//根据给定的主机名或点分十进制IP地址获得socket_in结构存储的地址
	int start_up(void); //Windows Sockets 初始化函数
	int clean_up(void); //Windows Sockets 资源释放函数
	int quit(SOCKET s); //退出处理函数
	SOCKET udp_server(char* hname, char* sname);//流式套接字服务器初始化函数
	int recvn(SOCKET s, char* recvbuf, unsigned int fixedlen); //接收定长数据
	int recvvl(SOCKET s, char* recvbuf, unsigned int recvbuflen);//接收变长数据
	SOCKET udp_client(char* hname, char* sname); //流式套接字客户端初始化函数

};
