#include "XTPRibbonBarZ.h"

IMPLEMENT_XTP_COMMANDBAR(CXTPRibbonBarZ, CXTPRibbonBar)

BEGIN_MESSAGE_MAP(CXTPRibbonBarZ, CXTPRibbonBar)
	//{{AFX_MSG_MAP(CXTPRibbonBar)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CXTPRibbonBarZ::CXTPRibbonBarZ():CXTPRibbonBar(){
;
}

CXTPRibbonBarZ::~CXTPRibbonBarZ(){
;
}

void CXTPRibbonBarZ::OnLButtonDblClk(UINT nFlags, CPoint point) {
	int nHit = HitTestCaption(point);

	if ((nHit == HTNOWHERE) && IsFrameThemeEnabled() && m_pContextHeaders->HitTest(point))
		nHit = HTCAPTION;

	if (nHit == HTCAPTION || nHit == HTSYSMENU)
	{
		CWnd* pSite = GetSite();
		ClientToScreen(&point);

		::DefWindowProc(pSite->GetSafeHwnd(), WM_NCLBUTTONDBLCLK, nHit, MAKELPARAM(point.x, point.y));
		return;
	}

	CXTPTabManagerItem* pItem = m_pControlTab->HitTest(point);
	if (pItem && pItem == GetSelectedTab() && m_bAllowMinimize)
	{
		if (IsRibbonMinimized())
		{
			SetRibbonMinimized(FALSE);
		}
		else if (m_bMinimizeOnDblClick)
		{
			SetRibbonMinimized(TRUE);
		}
		m_bMinimizeOnDblClick = TRUE;
	}
	
	return;
}