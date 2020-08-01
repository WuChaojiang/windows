// main.cpp:
#include "stdafx.h"
#include "FirstWindow.h"
CAppModule _Module;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	_Module.Init(NULL, hInstance);
	AtlInitCommonControls(ICC_COOL_CLASSES | ICC_BAR_CLASSES);
	MSG msg;

	FirstWindow window;
	//CRect rc;
	//rc.top = 10;
	//rc.bottom = 500;
	//rc.left = 10;
	//rc.right = 500;
	//window.Create(NULL, rc, L"蜂网-风行号上传工具", WS_VISIBLE | WS_SYSMENU, NULL, 0u, NULL);
	window.DoModal();

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	_Module.Term();
	return msg.wParam;
}