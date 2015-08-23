#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief 主程序容器,用于执行ZY system的所有功能.
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../stdafx.h"

namespace ZYSystem {

	class IndexGraphPane : public CView
	{
	public:
		CXTPChartControl m_wndChartControl;

		IndexGraphPane();
		void UpdateHistory();
		virtual void OnDraw(CDC* pDC);  //overridden to draw this view
		
		virtual BOOL PreCreateWindow(CREATESTRUCT& CS);
		virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
		virtual ~IndexGraphPane();

	protected:
		afx_msg void OnClose();
		afx_msg void OnDestroy();
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnSize(UINT nType, int cx, int cy);
		afx_msg BOOL OnEraseBkgnd(CDC* pDC);
		afx_msg void OnSetFocus(CWnd* pOldWnd);

		DECLARE_MESSAGE_MAP();
	};
}