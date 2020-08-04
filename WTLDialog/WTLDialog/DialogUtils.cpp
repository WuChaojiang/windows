#include "stdafx.h"
#include "resource.h"
#include "DialogUtils.h"


BOOL imageFromIDResource(UINT nID, LPCTSTR type, Image * &pImg)
{
	HINSTANCE hInst = _Module.get_m_hInst();
	HRSRC hRsrc = ::FindResource(hInst, MAKEINTRESOURCE(nID), type); // type
	if (!hRsrc)
		return FALSE;

	// load resource into memory
	DWORD len = SizeofResource(hInst, hRsrc);
	BYTE* lpRsrc = (BYTE*)LoadResource(hInst, hRsrc);
	if (!lpRsrc)
		return FALSE;

	// Allocate global memory on which to create stream
	HGLOBAL m_hMem = GlobalAlloc(GMEM_FIXED, len);
	BYTE* pmem = (BYTE*)GlobalLock(m_hMem);
	memcpy(pmem,lpRsrc,len);
	IStream* pstm;
	CreateStreamOnHGlobal(m_hMem,FALSE,&pstm);
	// load from stream
	pImg=Gdiplus::Image::FromStream(pstm);
	// free/release stuff
	GlobalUnlock(m_hMem);
	pstm->Release();
	FreeResource(lpRsrc);

	return TRUE;
}