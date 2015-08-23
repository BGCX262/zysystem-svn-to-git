/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.cpp
///@brief 实现 用于上期技术综合交易平台的行情服务接口类
///@author 张弛
///@date 20130818
/////////////////////////////////////////////////////////////////////////
#include "ZYsystemDoc.h"

using namespace ZYSystem;

IMPLEMENT_DYNCREATE(ZYsystemDoc, CDocument)

BEGIN_MESSAGE_MAP(ZYsystemDoc, CDocument)
	
END_MESSAGE_MAP()

ZYsystemDoc::ZYsystemDoc()
{
	// TODO: add one-time construction code here

}

ZYsystemDoc::~ZYsystemDoc()
{
}

BOOL ZYsystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// ZYsystemDoc serialization

void ZYsystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}