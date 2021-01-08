
// LANChatDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "LANChat.h"
#include "LANChatDlg.h"
#include "afxdialogex.h"
#include "Resource.h"
#include <time.h>
#pragma warning(disable:4996)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnIpnFieldchangedIpaddress(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedRadioServer();
	afx_msg void OnBnClickedRadioClient();
	afx_msg void OnBnClickedBegin();
	afx_msg void OnBnClickedSend();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS, &CAboutDlg::OnIpnFieldchangedIpaddress)
	ON_BN_CLICKED(IDC_RADIO_SERVER, &CAboutDlg::OnBnClickedRadioServer)
	ON_BN_CLICKED(IDC_RADIO_CLIENT, &CAboutDlg::OnBnClickedRadioClient)
	ON_BN_CLICKED(IDC_BEGIN, &CAboutDlg::OnBnClickedBegin)
	ON_BN_CLICKED(IDC_SEND, &CAboutDlg::OnBnClickedSend)
END_MESSAGE_MAP()


// CLANChatDlg 对话框



CLANChatDlg::CLANChatDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LANCHAT_DIALOG, pParent)
	, m_usPort(0)
	, m_nServerType(0)
	, m_ulIP(0)
	, m_SendText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_usPort = 7210;//
}

void CLANChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PORT, m_usPort);
	DDX_Radio(pDX, IDC_RADIO_SERVER, m_nServerType);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_IPAddress(pDX, IDC_IPADDRESS, m_ulIP);
	DDX_Text(pDX, IDC_SENDTEXT, m_SendText);
}

BEGIN_MESSAGE_MAP(CLANChatDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_RADIO_SERVER, &CLANChatDlg::OnBnClickedRadioServer)
	ON_BN_CLICKED(IDC_RADIO_CLIENT, &CLANChatDlg::OnBnClickedRadioClient)
	ON_BN_CLICKED(IDC_BEGIN, &CLANChatDlg::OnBnClickedBegin)
	ON_BN_CLICKED(IDC_SEND, &CLANChatDlg::OnBnClickedSend)
	ON_MESSAGE(WM_READ, &CLANChatDlg::OnRecvFrom)
END_MESSAGE_MAP()



// CLANChatDlg 消息处理程序

BOOL CLANChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	GetDlgItem(IDC_IPADDRESS)->SetWindowText(_T("127.0.0.1"));
	GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_SENDTEXT)->EnableWindow(FALSE);
	memset(&m_peer, 0, sizeof(m_peer));
	memset(&m_local, 0, sizeof(m_local));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLANChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLANChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLANChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedRadioServer()
{
	m_nServerType = SERVER;
	UpdateData(TRUE);
}


void CAboutDlg::OnBnClickedRadioClient()
{
	m_nServerType = CLIENT;
	UpdateData(TRUE);
}


void CAboutDlg::OnBnClickedBegin()
{
	CSocketFrame frame;
	int iResult = 0;

	UpdateData(TRUE);

	//Windows Sockets Dll初始化
	frame.start_up();

	//当程序作为服务器
	if (m_nServerType == SERVER)
	{
		//为服务器的本地地址m_local设置用户输入的IP和端口号
		memset(&m_local, 0, sizeof(m_local));
		m_local.sin_family = AF_INET;
		m_local.sin_addr.S_un.S_addr = htonl(m_ulIP);
		m_local.sin_port = htons(m_usPort);
		//创建服务器端的数据报套接字并在指定端口号上监听
		m_Socket = frame.udp_server(0, m_usPort);
		if (m_Socket == -1)
		{
			m_List.InsertString(0, "服务器启动失败");
			return;
		}
		m_List.InsertString(0, _T("服务器已启动"));
	}
	else
	{
		//创建客户端的数据报套接字并向服务器请求建立连接
		UpdateData(TRUE);
		if (m_ulIP == 0 || m_usPort == 0)
		{
			m_List.InsertString(0, "IP 地址不能为空");
			return;
		}
		// 指明服务器的地址m_peer为用户输入的IP和端口号
		memset(&m_peer, 0, sizeof(m_peer));
		m_peer.sin_family = AF_INET;
		m_peer.sin_addr.S_un.S_addr = htonl(m_ulIP);
		m_peer.sin_port = htons(m_usPort);
		// 创建客户端的数据报套接字
		m_Socket = frame.udp_client(m_ulIP, m_usPort, FALSE);
		if (m_Socket == -1)
		{
			m_List.InsertString(0, "客户端启动失败");
			return;
		}
		m_List.InsertString(0, _T("客户端已启动"));
	}
	iResult = WSAAsyncSelect(m_Socket, m_hWnd, WM_READ, FD_READ);
	if (iResult == SOCKET_ERROR)
	{
		m_List.InsertString(0, "WSAAsyncSelect设定失败!");
		return;
	}

	//更新对话框控件的可操作性
	GetDlgItem(IDC_SENDTEXT)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_IPADDRESS)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_SERVER)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_CLIENT)->EnableWindow(FALSE);
	GetDlgItem(IDC_PORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BEGIN)->EnableWindow(FALSE);
}


void CAboutDlg::OnBnClickedSend()
{
	time_t    ticks;
	char      buff[MAXLINE], info[MAXLINE];
	int iResult = -1;

	// 更新对话框里的数据
	UpdateData(TRUE);
	if (m_SendText.GetLength() > MAXLINE)
	{
		m_List.InsertString(0, "发送内容超长！");
		return;
	}
	if (m_peer.sin_addr.S_un.S_addr == 0)
	{
		m_List.InsertString(0, "目标地址为空，请确定正确的目标地址！");
		return;
	}

	// 获取当前时间
	ticks = time(NULL);
	memset(buff, 0, sizeof(buff));
	sprintf_s(buff, MAXLINE, "%.24s\r\n", ctime(&ticks));

	if (m_nServerType == SERVER)
	{
		sprintf_s(info, MAXLINE, "%s服务器向%s发送数据:", buff, inet_ntoa(m_peer.sin_addr));
	}
	else
	{
		sprintf_s(info, MAXLINE, "%s客户端向%s发送数据:", buff, inet_ntoa(m_peer.sin_addr));
	}
	// 发送数据
	iResult = sendto(m_Socket, m_SendText.GetBuffer(m_SendText.GetLength()), m_SendText.GetLength(), 0, (SOCKADDR*)& m_peer, sizeof(m_peer));
	if (iResult == SOCKET_ERROR)
	{
		sprintf_s(info, MAXLINE, "sendto函数调用错误，错误号：%d", WSAGetLastError());
		m_List.InsertString(0, info);
		closesocket(m_Socket);
	}
	else
	{
		m_List.InsertString(0, info + m_SendText);
	}
	m_SendText.ReleaseBuffer();
}


LRESULT CLANChatDlg::OnRecvFrom(WPARAM wParam, LPARAM lParam)
{
	int     iResult;
	time_t	ticks;
	char	buff[MAXLINE], info[MAXLINE];
	char    recvbuf[MAXLINE];
	struct  sockaddr_in	cliaddr;
	int addrlen = sizeof(sockaddr_in);
	CString str;
	memset(recvbuf, 0, MAXLINE);

	// 获取当前时间
	ticks = time(NULL);
	memset(buff, 0, sizeof(buff));
	sprintf_s(buff, MAXLINE, "%.24s\r\n", ctime(&ticks));


	// 判断网络事件
	if (WSAGETSELECTERROR(lParam))
		m_List.InsertString(0, "套接字错误。");
	else
	{
		switch (WSAGETSELECTEVENT(lParam))
		{
		case FD_READ:
			// 接收数据
			iResult = recvfrom(m_Socket, recvbuf, MAXLINE, 0, (SOCKADDR*)& cliaddr, &addrlen);
			if (iResult == SOCKET_ERROR)
			{
				sprintf_s(info, MAXLINE, "%s接收数据发生错误，错误号：%d", buff, WSAGetLastError());
				str = info;
				m_List.InsertString(0, str);
				return 0;
			}
			sprintf_s(info, MAXLINE, "%s接收到来自%s的数据：", buff, inet_ntoa(cliaddr.sin_addr));
			str = info;
			m_List.InsertString(0, str + recvbuf);

			// 更新通信对方地址
			m_peer = cliaddr;
			break;
		default:
			break;
		}
	}
	return 0;

}
