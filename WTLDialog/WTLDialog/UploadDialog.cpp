#include "UploadDialog.h"

#include <GdiPlus.h>
using namespace Gdiplus;
extern GdiplusStartupInput gGdiInput;

#pragma  comment(lib, "GdiPlus.lib")

#include "DialogUtils.h"


CUploadDialog::CUploadDialog(void)
{
	m_fontTitle.CreatePointFont(150,_T("幼圆"), NULL, true);
	m_fontListFile.CreatePointFont(130,_T("楷书"));
}


CUploadDialog::~CUploadDialog(void)
{
}


LRESULT CUploadDialog::OnInitDialog( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	ULONG  token = 0;
	GdiplusStartup(&token, &gGdiInput, NULL);

	m_staicTitle = (CStatic)GetDlgItem(IDC_UPLOAD_TITLE);
	m_staicTitle.SetFont(m_fontTitle);

	m_staicListFile = (CStatic)GetDlgItem(IDC_FILE_LIST);	
	m_staicListFile.SetFont(m_fontListFile);
	
	m_listVideo = (CListBox)GetDlgItem(IDC_LIST_VEDIO);
	m_listVideo.InsertString(0, L"D:\\res");
	m_listVideo.InsertString(0, L"D:\\Software");
	m_listVideo.InsertString(0, L"D:\\tools\\apache_httpd");
	m_listVideo.InsertString(0, L"D:\\VS09_PROJECTS\\Awesomium");

	m_radioLogin = (CButton)GetDlgItem(IDC_RADIO_LOGIN);
	m_radioLogin.SetCheck(1);

	SetWindowLong(GWL_STYLE, GetWindowLong(GWL_STYLE)&(~(WS_CAPTION | WS_BORDER)));
	CenterWindow();

	DoDataExchange();

	return TRUE;
}


LRESULT CUploadDialog::OnClose( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	EndDialog(100);
	
	return TRUE;
}

LRESULT CUploadDialog::OnPaint( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
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

LRESULT CUploadDialog::OnBnClickedBtnAddFolder(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	ATL::CString filter = "文本文档(*.txt)|*.txt|所有文件(*.*)|*.*||";
	CFolderDialog folderDlg;
	ATL::CString strFolderPath;
	if(folderDlg.DoModal() == IDOK)   
	{
		strFolderPath = folderDlg.GetFolderPath();    //获得路径
		//文件夹路径 D:/xxxx
		
		m_listVideo.InsertString(0, strFolderPath);
		//POSITION pos;
		//pos=OpenFileDialog.GetStartPosition();//开始遍历用户选择文件列表
		//while (pos!=NULL)
		//{
		//	CString filename=OpenFileDialog.GetNextPathName(pos);
		//	Msg+=filename+"\r\n";
		//}
		//MessageBox(Msg);
	}    

	return 0;
}


LRESULT CUploadDialog::OnBnClickedBtnMsg(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add your control notification handler code here

	MessageBox(L"暂时没有消息", L"信息", MB_ICONINFORMATION);
	return 0;
}


LRESULT CUploadDialog::OnBnClickedBtnDelFolder(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	int nIndex = m_listVideo.GetCurSel();
	m_listVideo.DeleteString(nIndex);
	return 0;
}
