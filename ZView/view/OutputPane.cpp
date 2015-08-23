/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.cpp
///@brief 实现 用于上期技术综合交易平台的行情服务接口类
///@author 张弛
///@date 20130818
/////////////////////////////////////////////////////////////////////////
#include "OutputPane.h"

using namespace ZYSystem;

OutputPane::OutputPane()
{
}

OutputPane::~OutputPane()
{
}

BEGIN_MESSAGE_MAP(OutputPane, CEdit)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

int OutputPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	ModifyStyleEx(0, WS_EX_STATICEDGE);

	SetFont(XTPPaintManager()->GetRegularFont());
	SetMargins(10, 5);

	return 0;
}

void OutputPane::OnSize(UINT nType, int cx, int cy)
{
	CEdit::OnSize(nType, cx, cy);

}