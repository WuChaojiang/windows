#pragma once
#include "stdafx.h"

class CButtonImpl : public CWindowImpl<CButtonImpl, CButton>
{
	BEGIN_MSG_MAP_EX(CButtonImpl)
		MSG_WM_SETCURSOR(OnSetCursor)
		END_MSG_MAP()

		LRESULT OnSetCursor(HWND hwndCtrl, UINT uHitTest, UINT uMouseMsg)
		{
			static HCURSOR hcur = LoadCursor ( NULL, IDC_SIZEALL );

			if ( NULL != hcur )
			{
				SetCursor ( hcur );
				return TRUE;
			}
			else
			{
				SetMsgHandled(false);
				return FALSE;
			}
		}
};
class CEditImpl : public CWindowImpl<CEditImpl, CEdit>
{
	BEGIN_MSG_MAP_EX(CEditImpl)
		MSG_WM_CONTEXTMENU(OnContextMenu)
		END_MSG_MAP()

		void OnContextMenu ( HWND hwndCtrl, CPoint ptClick )
		{
			MessageBox("Edit control handled WM_CONTEXTMENU");
		}
};

class CLoginDialog : public CDialogImpl<CLoginDialog>£¬ 
	public CWinDataExchange<CMainDlg>
{
protected:
	CLoginDialog();
	CContainedWindow m_wndOKBtn, m_wndExitBtn;

public:
	BEGIN_MSG_MAP_EX(CLoginDialog)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
		ALT_MSG_MAP(1)
		MSG_WM_SETCURSOR(OnSetCursor_OK)
		ALT_MSG_MAP(2)
		MSG_WM_SETCURSOR(OnSetCursor_Exit)
		END_MSG_MAP()

		LRESULT OnSetCursor_OK(HWND hwndCtrl, UINT uHitTest, UINT uMouseMsg);
		LRESULT OnSetCursor_Exit(HWND hwndCtrl, UINT uHitTest, UINT uMouseMsg);
		LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult);
		LRESULT OnAppAbout(HWND hwndCtrl, UINT uHitTest, UINT uMouseMsg);
		
private:
	CContainedWindow m_wndOKBtn, m_wndExitBtn;
	CButtonImpl m_wndAboutBtn;
	CEditImpl   m_wndEdit;
};
