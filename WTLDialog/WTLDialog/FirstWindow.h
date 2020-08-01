#pragma once
#include "stdafx.h"
#include "resource.h"

//class FirstWindow : public CWindowImpl<FirstWindow, CWindow> 
class FirstWindow : public CDialogImpl<FirstWindow> 
{
public:
	enum 
	{
		IDD = IDD_DLG_LOGIN
	};
	FirstWindow(){}
	~FirstWindow(){}
	BEGIN_MSG_MAP(FirstWindow)
	END_MSG_MAP()
};
