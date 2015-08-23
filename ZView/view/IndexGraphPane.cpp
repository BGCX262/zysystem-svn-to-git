/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.cpp
///@brief 实现 用于上期技术综合交易平台的行情服务接口类
///@author 张弛
///@date 20130818
/////////////////////////////////////////////////////////////////////////
#include "IndexGraphPane.h"

using namespace ZYSystem;

IndexGraphPane::IndexGraphPane()
{

}

IndexGraphPane::~IndexGraphPane()
{

}

BEGIN_MESSAGE_MAP(IndexGraphPane, CView)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

BOOL IndexGraphPane::PreCreateWindow(CREATESTRUCT& cs)
{
	return CWnd::PreCreateWindow(cs);
}

int IndexGraphPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	if(!m_wndChartControl.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 0))
	{
		TRACE0("Error creating chart control.\n");
		return -1;
	}
	ModifyStyleEx(WS_EX_CLIENTEDGE, 0);

	m_wndChartControl.GetContent()->GetAppearance()->LoadAppearance(_T("CHART_APPEARANCE_GRAY"));
	
	m_wndChartControl.GetContent()->GetLegend()->SetVisible(TRUE);
	
	UpdateHistory();

	return 0;
}

void IndexGraphPane::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	if (m_wndChartControl.GetSafeHwnd())
	{
		m_wndChartControl.MoveWindow(0, 0, cx, cy);
	}
}

void IndexGraphPane::OnSetFocus(CWnd* /*pOldWnd*/)
{
	m_wndChartControl.SetFocus();
}

BOOL IndexGraphPane::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void IndexGraphPane::OnDraw(CDC* pDC)
{
}

void IndexGraphPane::UpdateHistory()
{
	m_wndChartControl.GetContent()->GetSeries()->RemoveAll();

	CXTPChartSeries* pSeries = m_wndChartControl.GetContent()->GetSeries()->Add(new CXTPChartSeries());	
    CXTPChartHighLowSeriesStyle* pStyle = NULL;    
    pStyle = (CXTPChartHighLowSeriesStyle*)pSeries->SetStyle(new CXTPChartCandleStickSeriesStyle());
	
	CXTPChartDiagram2D* pDiagram = (CXTPChartDiagram2D*)pSeries->GetDiagram();
	pDiagram->GetAxisX()->GetCustomLabels()->RemoveAll();
	
	pDiagram->GetAxisY()->GetGridLines()->SetMinorVisible(TRUE);
	pDiagram->GetAxisY()->GetGridLines()->SetVisible(TRUE);
	pDiagram->GetAxisY()->GetGridLines()->GetMinorLineStyle()->SetDashStyle(xtpChartDashStyleSolid);
	
	pDiagram->GetAxisY()->GetTitle()->SetVisible(TRUE);
	pDiagram->GetAxisY()->SetMinorCount(10);
	pDiagram->GetAxisY()->GetRange()->SetMinValue(2);
	pDiagram->GetAxisY()->GetRange()->SetMaxValue(7);
	pDiagram->GetAxisY()->GetRange()->SetAutoRange(FALSE);
	pDiagram->GetAxisY()->GetRange()->SetShowZeroLevel(FALSE);
	
	pDiagram->GetAxisX()->GetGridLines()->SetMinorVisible(TRUE);
	pDiagram->GetAxisX()->GetGridLines()->SetVisible(TRUE);
	pDiagram->GetAxisX()->GetGridLines()->GetMinorLineStyle()->SetDashStyle(xtpChartDashStyleSolid);

	pDiagram->GetAxisX()->SetMinorCount(10);
	pDiagram->GetAxisX()->GetRange()->SetMaxValue(10);
	pDiagram->GetAxisX()->GetRange()->SetMinValue(1);
	pDiagram->GetAxisX()->GetRange()->SetAutoRange(FALSE);
	pDiagram->GetAxisX()->GetLabel()->SetAngle(0);
	pDiagram->GetAxisX()->GetLabel()->SetVisible(TRUE); 


	for(int i = 0;i <= 10;i++)
	{
		CString cs;
		cs.Format(_TEXT("%d"),i);
		CXTPChartAxisCustomLabel* pLabel = new CXTPChartAxisCustomLabel();
		pLabel->SetAxisValue(i);
		pLabel->SetText(cs);
		pDiagram->GetAxisX()->GetCustomLabels()->Add(pLabel);

		CXTPChartSeriesPoint *p = new CXTPChartSeriesPoint(i,3,6,4,5);
		p->SetArgumentValue(i);
		pSeries->GetPoints()->Add(p);
	}
}

void IndexGraphPane::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	UpdateHistory();
}

void IndexGraphPane::OnDestroy()
{
	return;
}

void IndexGraphPane::OnClose(){
	return;
}