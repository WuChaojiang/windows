#include "LoginDialog.h"


CLoginDialog::CLoginDialog(void) : m_wndOKBtn(this, 1), 
	m_wndExitBtn(this, 2)
{
}

CLoginDialog::~CLoginDialog(void)
{
}

LRESULT CLoginDialog::OnSetCursor_OK (
	HWND hwndCtrl, UINT uHitTest, UINT uMouseMsg )
{
	static HCURSOR hcur = LoadCursor ( NULL, IDC_HAND );

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

LRESULT CLoginDialog::OnSetCursor_Exit (
	HWND hwndCtrl, UINT uHitTest, UINT uMouseMsg )
{
	static HCURSOR hcur = LoadCursor ( NULL, IDC_NO );

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

LRESULT CLoginDialog::OnInitDialog( UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult )
{
	// Attach CContainedWindows to OK and Exit buttons
	m_wndOKBtn.SubclassWindow ( GetDlgItem(IDOK) );
	m_wndExitBtn.SubclassWindow ( GetDlgItem(IDCANCEL) );
	// CButtonImpl: subclass the About button
	m_wndAboutBtn.SubclassWindow ( GetDlgItem(ID_APP_ABOUT) );
	return TRUE;
}
