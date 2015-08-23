/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.cpp
///@brief 实现 用于上期技术综合交易平台的行情服务接口类
///@author 张弛
///@date 20130818
/////////////////////////////////////////////////////////////////////////
#include "MarketDataPane.h"

using namespace ZYSystem;

MarketDataPane::MarketDataPane()
{
}

MarketDataPane::~MarketDataPane()
{
}

BEGIN_MESSAGE_MAP(MarketDataPane, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

int MarketDataPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (m_wndPropertyGrid.GetSafeHwnd() == 0)
	{
		m_wndPropertyGrid.Create( CRect(0, 0, 0, 0), this, 0 );
		m_wndPropertyGrid.SetOwner(this);

		CFont font;
		font.CreatePointFont(100, _T("Marlett"));

		LOGFONT lf;
		font.GetLogFont(&lf);
	}

	return 0;
}

void MarketDataPane::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	int nTop = 0;

	if (m_wndPropertyGrid.GetSafeHwnd())
	{
		m_wndPropertyGrid.MoveWindow(0, nTop, cx, cy - nTop);
		m_wndPropertyGrid.Invalidate(FALSE);
	}
}




void MarketDataPane::OnPanePropertiesCategorized()
{
	m_wndPropertyGrid.SetPropertySort(xtpGridSortCategorized);

}

void MarketDataPane::OnUpdatePanePropertiesCategorized(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndPropertyGrid.GetPropertySort() == xtpGridSortCategorized);

}

void MarketDataPane::OnPanePropertiesAlphabetic()
{
	m_wndPropertyGrid.SetPropertySort(xtpGridSortAlphabetical);

}

void MarketDataPane::OnUpdatePanePropertiesAlphabetic(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndPropertyGrid.GetPropertySort() == xtpGridSortAlphabetical);

}

void MarketDataPane::OnSetFocus(CWnd* /*pOldWnd*/)
{
	m_wndPropertyGrid.SetFocus();
}

void MarketDataPane::OnDraw(CDC* pDC) {

}
