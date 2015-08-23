/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.cpp
///@brief 实现 用于上期技术综合交易平台的行情服务接口类
///@author 张弛
///@date 20130818
/////////////////////////////////////////////////////////////////////////
#include "MainFrm.h"

using namespace ZYSystem;

IMPLEMENT_DYNAMIC(MainFrame, CXTPMDIFrameWnd)

BEGIN_MESSAGE_MAP(MainFrame, CXTPMDIFrameWnd)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_WINDOWPOSCHANGED()
	ON_MESSAGE(XTPWM_DOCKINGPANE_NOTIFY, OnDockingPaneNotify)
END_MESSAGE_MAP()



MainFrame::MainFrame()
{
	// TODO: add member initialization code here
}

MainFrame::~MainFrame()
{

}

int MainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return FALSE;

	if (!InitCommandBars())
		return FALSE;

	XTPPaintManager()->SetTheme(xtpThemeRibbon);
	if (!CreateRibbonBar())
	{
		TRACE0("Failed to create ribbon\n");
		return FALSE;
	}

	m_paneManager.InstallDockingPanes(this);
	
	// Create docking panes.
	CXTPDockingPane* pwndPaneIndexGraph = m_paneManager.CreatePane(IDR_PANE_IndexGraph,CRect(0, 0,500, 700), xtpPaneDockTop);
	CXTPDockingPane* pwndPaneOutput = m_paneManager.CreatePane(IDR_PANE_Output,CRect(0, 0,500, 700), xtpPaneDockBottom,pwndPaneIndexGraph);

	CXTPDockingPane* pwndPaneMarketData = m_paneManager.CreatePane(IDR_PANE_MarketData, CRect(0, 0,380, 360), xtpPaneDockLeft);
	CXTPDockingPane* pwndPaneIndexData = m_paneManager.CreatePane(IDR_PANE_IndexData, CRect(0, 0,380, 360), xtpPaneDockBottom, pwndPaneMarketData);
	CXTPDockingPane* pwndPaneSignarData = m_paneManager.CreatePane(IDR_PANE_Signar, CRect(0, 0,380, 360), xtpPaneDockBottom, pwndPaneIndexData);

	CXTPDockingPane* pwndPaneFund = m_paneManager.CreatePane(IDR_PANE_Fund, CRect(0, 0,380, 360), xtpPaneDockRight);
	CXTPDockingPane* pwndPaneOrder = m_paneManager.CreatePane(IDR_PANE_Order, CRect(0, 0,380, 360), xtpPaneDockBottom, pwndPaneFund);
	CXTPDockingPane* pwndPaneTrade = m_paneManager.CreatePane(IDR_PANE_Trade, CRect(0, 0,380, 360), xtpPaneDockBottom, pwndPaneOrder);
	
	m_paneManager.SetAlphaDockingContext(TRUE);
	m_paneManager.SetShowDockingContextStickers(TRUE);
	m_paneManager.SetShowContentsWhileDragging(TRUE);
	m_paneManager.SetTheme(xtpPaneThemeVisualStudio2010);
	
	return TRUE;
}

BOOL MainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.lpszClass = _T("XTPMainFrame");
	CXTPDrawHelpers::RegisterWndClass(AfxGetInstanceHandle(), cs.lpszClass, CS_DBLCLKS, AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	return TRUE;
 }

void MainFrame::OnClose(){

	// Save the current state for docking panes.
	CXTPMDIFrameWnd::OnClose();
}

LRESULT MainFrame::OnDockingPaneNotify(WPARAM wParam, LPARAM lParam)
{
	if (wParam == XTP_DPN_SHOWWINDOW)
	{
		CXTPDockingPane* pPane = (CXTPDockingPane*)lParam;

		if (!pPane->IsValid()) {
			switch (pPane->GetID())
			{
			case IDR_PANE_Fund: {
					if (m_wndFundPane.GetSafeHwnd() == 0){
						m_wndFundPane.Create(_T("STATIC"), NULL, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CXTPEmptyRect(), this, IDR_PANE_Fund);
					}
					pPane->Attach(&m_wndFundPane);
					break;
				}
			case IDR_PANE_IndexData:{
					if (m_wndIndexDataPane.GetSafeHwnd() == 0){
						m_wndIndexDataPane.Create(_T("STATIC"), NULL, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CXTPEmptyRect(), this, IDR_PANE_IndexData);
					}
					pPane->Attach(&m_wndIndexDataPane);
					break;
				}
			case IDR_PANE_IndexGraph:{
					if (m_wndIndexGraph.GetSafeHwnd() == 0){
						m_wndIndexGraph.Create(_T("STATIC"), NULL, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CXTPEmptyRect(), this, IDR_PANE_IndexGraph);
					}
					pPane->Attach(&m_wndIndexGraph);
					break;
				}
			case IDR_PANE_MarketData:{
					if (m_wndMarketDataPane.GetSafeHwnd() == 0){
						m_wndMarketDataPane.Create(_T("STATIC"), NULL, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CXTPEmptyRect(), this, IDR_PANE_MarketData);
					}
					pPane->Attach(&m_wndMarketDataPane);
					break;
				}
			case IDR_PANE_Order:{
					if (m_wndOrderPane.GetSafeHwnd() == 0){
						m_wndOrderPane.Create(_T("STATIC"), NULL, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CXTPEmptyRect(), this, IDR_PANE_Order);
					}
					pPane->Attach(&m_wndOrderPane);
					break;
				}
			case IDR_PANE_Output:{
					if (m_wndOutputPane.GetSafeHwnd() == 0){
						m_wndOutputPane.Create(WS_HSCROLL|ES_AUTOHSCROLL|ES_MULTILINE|WS_VISIBLE, CXTPEmptyRect(), this, IDR_PANE_Output);
					}
					pPane->Attach(&m_wndOutputPane);
					break;
				}
			case IDR_PANE_Signar:{
					if (m_wndSignarPane.GetSafeHwnd() == 0){
						m_wndSignarPane.Create(_T("STATIC"), NULL, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CXTPEmptyRect(), this, IDR_PANE_Signar);
					}
					pPane->Attach(&m_wndSignarPane);
					break;
				}
			case IDR_PANE_Trade:{
					if (m_wndTradePane.GetSafeHwnd() == 0){
						m_wndTradePane.Create(_T("STATIC"), NULL, WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CXTPEmptyRect(), this, IDR_PANE_Trade);
					}
					pPane->Attach(&m_wndTradePane);
					break;
				}
			}
		}
		return TRUE;
	}
	return FALSE;
}

BOOL MainFrame::CreateRibbonBar()
{
	CXTPCommandBars* pCommandBars = GetCommandBars();

	CXTPPropExchangeXMLNode px(TRUE, 0, _T("Settings"));

	if (px.LoadFromResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_LAYOUT), RT_HTML))
	{
		CXTPPropExchangeSection pxCommandBars(px.GetSection(_T("CommandBars")));
		XTP_COMMANDBARS_PROPEXCHANGE_PARAM param; 
		param.bSerializeControls = TRUE;
		GetCommandBars()->DoPropExchange(&pxCommandBars, &param);
	}
	else
	{
		AfxMessageBox(_T("Can't load Layout"));
		return FALSE;
	}
	CXTPRibbonBarZ* pRibbonBar = (CXTPRibbonBarZ*)GetCommandBars()->GetMenuBar();
	pRibbonBar->EnableCustomization(FALSE);
	pRibbonBar->EnableFrameTheme();
	pRibbonBar->AllowMinimize(FALSE);
	pRibbonBar->AllowQuickAccessCustomization(FALSE);
	pRibbonBar->ShowQuickAccess(FALSE);

	return TRUE;
}

void MainFrame::OnDestroy()
{
	CMDIFrameWnd::OnDestroy();
//	delete m_wndMarketDataPane;
}