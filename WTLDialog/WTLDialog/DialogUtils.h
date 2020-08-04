#pragma once

#include <GdiPlus.h>
using namespace Gdiplus;


BOOL imageFromIDResource(UINT nID, LPCTSTR type, Image * &pImg);