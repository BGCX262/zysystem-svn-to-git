#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2013 ZYSystem by Ziumsoft.
///@file CMainFrame.h
///@brief 主框架,定义了ZYsystem内所有的窗体和定位.
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "view/FundPane.h"
#include "view/IndexDataPane.h"
#include "view/IndexGraphPane.h"
#include "view/MarketDataPane.h"
#include "view/OrderPane.h"
#include "view/OutputPane.h"
#include "view/SignarPane.h"
#include "view/TradePane.h"
#include "controls/XTPRibbonBarZ.h"

namespace ZYSystem {

	class MainFrame : public CXTPMDIFrameWnd
	{
	DECLARE_DYNAMIC(MainFrame)
	
	public:
		MainFrame();

		virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
		virtual ~MainFrame();
		BOOL CreateRibbonBar();
		void LoadIcons();

	protected: 
		CXTPDockingPaneManager m_paneManager;
		
		FundPane m_wndFundPane;
		IndexDataPane m_wndIndexDataPane;
		IndexGraphPane m_wndIndexGraph;
		MarketDataPane m_wndMarketDataPane;
		OrderPane m_wndOrderPane;
		OutputPane m_wndOutputPane;
		SignarPane m_wndSignarPane;
		TradePane m_wndTradePane;

		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnClose();
		afx_msg void OnDestroy();
		afx_msg LRESULT OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);
		DECLARE_MESSAGE_MAP()
	};
}