
// LANChatDlg.h: 头文件
//

#pragma once
#include "SocketFrame.h"
#include "afxwin.h"
#include "Resource.h"
#define SERVER 0
#define CLIENT 1
#define WM_READ WM_USER+101


// CLANChatDlg 对话框
class CLANChatDlg : public CDialog
{
	// 构造
public:
	CLANChatDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LANCHAT_DIALOG };

	afx_msg void OnBnClickedRadioServer();
	afx_msg void OnBnClickedRadioClient();
	afx_msg void OnBnClickedBegin();
	UINT m_usPort;
	int m_nServerType;
	SOCKET m_Socket;
	struct sockaddr_in m_peer, m_local;

	afx_msg LRESULT OnRecvFrom(WPARAM wParam, LPARAM lParam);

	int GetLocalHostInfo(CString& strHostName, CString& strIPAddress);
	afx_msg void OnBnClickedSend();
	CListBox m_List;
	ULONG m_ulIP;
	CString m_SendText;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

};


