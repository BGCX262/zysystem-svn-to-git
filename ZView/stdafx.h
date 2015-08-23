#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief 主程序容器,用于执行ZY system的所有功能.
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STDAFX_H__5128F74D_6242_4586_A897_6F6EDDE36C3D__INCLUDED_)
#define AFX_STDAFX_H__5128F74D_6242_4586_A897_6F6EDDE36C3D__INCLUDED_

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers
#define _MSC_VER 1600
#define WINVER 0x0601
#define _WIN32_WINDOWS 0x0601
#define _WIN32_IE 0x0900
#define _WIN32_WINNT 0x0601


#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>         // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <WinUser.h>

// Lets help compiler to skip some headers
#define _XTP_EXCLUDE_CALENDAR
#define _XTP_EXCLUDE_REPORTCONTROL


//#define ENABLE_MANIFESTEDITOR

#include <XTToolkitPro.h>   // Codejock Software Components 

#include "resource.h"

#endif // !defined(AFX_STDAFX_H__5128F74D_6242_4586_A897_6F6EDDE36C3D__INCLUDED_)
