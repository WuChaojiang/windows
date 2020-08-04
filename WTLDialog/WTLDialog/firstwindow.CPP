#include "stdafx.h"
#include "FirstWindow.h"
#include <GdiPlus.h>
using namespace Gdiplus;
extern GdiplusStartupInput gGdiInput;

#pragma  comment(lib, "GdiPlus.lib")
GdiplusStartupInput gGdiInput;

#include "DialogUtils.h"

FirstWindow::FirstWindow()
{
	m_name = _T("");
	m_password = _T("");
	m_font.CreatePointFont(220,_T("Ó×Ô²"), NULL, true);
	m_fontSubTitle.CreatePointFont(150,_T("ÐÂËÎÌå"));
	m_fontStaticName.CreatePointFont(120, _T("¿¬Ìå"));
}

LRESULT FirstWindow::OnBnClickedBtnLogin(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	// TODO: Add your control notification handler code here

	DoDataExchange(TRUE);
	ATL::CString name = m_name;
	ATL::CString pwd = m_password;

	
	PostMessage(WM_CLOSE);

	return 0;
}

LRESULT FirstWindow::OnInitDialog( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	ULONG  token = 0;
	GdiplusStartup(&token, &gGdiInput, NULL);

	m_wndName = (CEdit)GetDlgItem(IDC_EDIT_NAME);

	m_ctlTitle = (CStatic)GetDlgItem(IDC_STATIC_TITLE);
	m_ctlTitle.SetFont(m_font);

	m_staticName = (CEdit)GetDlgItem(IDC_STATIC_NAME);
	m_staticName.SetFont(m_fontStaticName);
	m_staticPwd = (CEdit)GetDlgItem(IDC_STATIC_PASSWORD);
	m_staticPwd.SetFont(m_fontStaticName);

	m_ctlSubTitle = (CStatic)GetDlgItem(IDC_STATIC_SUBTITLE);
	m_ctlSubTitle.SetFont(m_fontSubTitle);

	SetWindowLong(GWL_STYLE, GetWindowLong(GWL_STYLE)&(~(WS_CAPTION | WS_BORDER)));
	CenterWindow();

	DoDataExchange();

	return TRUE;
}

LRESULT FirstWindow::OnClose( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	BOOL bRet = CDialogImpl::EndDialog(101);
	return TRUE;
}

LRESULT FirstWindow::OnStaticColor( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	HDC hdc = (HDC)wParam;
	HWND hwnd = (HWND) lParam;
	HBRUSH hbr = (HBRUSH)GetCurrentObject(hdc, OBJ_BRUSH);
	if (hwnd == m_ctlTitle.m_hWnd)
	{
		SetTextColor(hdc, RGB(0, 191, 255));
	}
	else if (hwnd == m_ctlSubTitle.m_hWnd)
	{
		SetTextColor(hdc, RGB(0, 191, 255));
	}
	else if (hwnd == m_staticName.m_hWnd)
	{
		SetTextColor(hdc, RGB(0, 191, 255));
	}
	else if (hwnd == m_staticPwd.m_hWnd)
	{
		SetTextColor(hdc, RGB(0, 191, 255));
	}

	return (LRESULT)hbr;
}



LRESULT FirstWindow::OnPaint( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	CPaintDC dc(m_hWnd);
	RECT rect;
	GetClientRect(&rect);

	HDC hDC = dc.m_hDC;
	Graphics g(hDC);
	Image *pImage = NULL;
	imageFromIDResource(IDR_JPG_BK, _T("JPG"),pImage); 
	g.DrawImage(pImage, 0, 0, rect.right-rect.left, rect.bottom-rect.top);
	
	return TRUE;
}
