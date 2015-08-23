/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief 主程序容器,用于执行ZY system的所有功能.
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "TradePane.h"

using namespace ZYSystem;

TradePane::TradePane(){
}

TradePane::~TradePane()
{
}

BEGIN_MESSAGE_MAP(TradePane, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

int TradePane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (m_listCtrl.GetSafeHwnd() == NULL)
	{
		m_listCtrl.Create(WS_CHILD|WS_VISIBLE|WS_HSCROLL|LVS_REPORT,
						  CRect(0, 0, 0, 0),
						  this,
						  IDC_PANE_Trade_List);
		
		m_listCtrl.SetOwner(this);
		
		m_listCtrl.InsertColumn(0, _T("Column One"),   LVCFMT_LEFT, 125);
		m_listCtrl.InsertColumn(1, _T("Column Two"),   LVCFMT_LEFT, 125);
		m_listCtrl.InsertColumn(2, _T("Column Three"), LVCFMT_LEFT, 125);
	}

	return 0;
}

void TradePane::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	if (m_listCtrl.GetSafeHwnd()) {
		m_listCtrl.MoveWindow(0, 0, cx, cy);
		m_listCtrl.Invalidate(FALSE);
	}
}

void TradePane::OnSetFocus(CWnd* /*pOldWnd*/)
{
	m_listCtrl.SetFocus();
}

void TradePane::OnDraw(CDC* pDC) {

}