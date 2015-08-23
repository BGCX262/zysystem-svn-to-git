/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.cpp
///@brief ʵ�� �������ڼ����ۺϽ���ƽ̨���������ӿ���
///@author �ų�
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