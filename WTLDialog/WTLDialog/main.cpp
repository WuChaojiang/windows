// main.cpp:
#include "stdafx.h"
#include "FirstWindow.h"
#include "UploadDialog.h"
CAppModule _Module;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	_Module.Init(NULL, hInstance);
	AtlInitCommonControls(ICC_COOL_CLASSES | ICC_BAR_CLASSES);
	MSG msg;

	FirstWindow window;
	int nRet = window.DoModal();

	CUploadDialog uploadDlg;
	nRet = uploadDlg.DoModal();

	::PostQuitMessage(0);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	_Module.Term();
	return msg.wParam;
}