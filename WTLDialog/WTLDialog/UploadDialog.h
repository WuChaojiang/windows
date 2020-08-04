#pragma once
#include "stdafx.h"
#include "resource.h"

class CUploadDialog : public CDialogImpl<CUploadDialog>, 
	public CWinDataExchange<CUploadDialog>

{
public:
	CUploadDialog(void);
	~CUploadDialog(void);

	enum 
	{
		IDD = IDD_DLG_UPLOAD
	};

	BEGIN_MSG_MAP(CUploadDialog)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		COMMAND_HANDLER(IDC_BTN_ADD_FOLDER, BN_CLICKED, OnBnClickedBtnAddFolder)
		COMMAND_HANDLER(IDC_BTN_MSG, BN_CLICKED, OnBnClickedBtnMsg)
		COMMAND_HANDLER(IDC_BTN_DEL_FOLDER, BN_CLICKED, OnBnClickedBtnDelFolder)
	END_MSG_MAP()

	BEGIN_DDX_MAP(CUploadDialog)
	END_DDX_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

private:
	CFont  m_fontTitle;
	CFont  m_fontListFile;

	CButton m_radioLogin;

	CListBox m_listVideo;

	CStatic m_staicTitle;
	CStatic m_staicListFile;
public:
	LRESULT OnBnClickedBtnAddFolder(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedBtnMsg(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedBtnDelFolder(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};