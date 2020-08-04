#pragma once
#include "stdafx.h"
#include "resource.h"

//class FirstWindow : public CWindowImpl<FirstWindow, CWindow> 
class FirstWindow : public CDialogImpl<FirstWindow>, 
	public CWinDataExchange<FirstWindow>
{
public:
	enum 
	{
		IDD = IDD_DLG_LOGIN
	};
	FirstWindow();
	~FirstWindow(){}
	BEGIN_MSG_MAP(FirstWindow)
		COMMAND_HANDLER(IDC_BTN_LOGIN, BN_CLICKED, OnBnClickedBtnLogin)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_CTLCOLORSTATIC,OnStaticColor)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
	END_MSG_MAP()

	BEGIN_DDX_MAP(FirstWindow)
		DDX_TEXT(IDC_EDIT_NAME, m_name)
		DDX_TEXT(IDC_EDIT_PASSWORD, m_password)
	END_DDX_MAP()

	LRESULT OnBnClickedBtnLogin(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnStaticColor(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	
	
private:
	CEdit m_wndName;
	CEdit m_wndPassword;
	CStatic m_ctlTitle;
	CStatic m_ctlSubTitle;

	CStatic m_staticName;
	CStatic m_staticPwd;

	ATL::CString m_name;
	ATL::CString m_password;
	
	CFont  m_font;
	CFont  m_fontSubTitle;
	CFont  m_fontStaticName;
};
