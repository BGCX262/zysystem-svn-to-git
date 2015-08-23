#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief ����������,����ִ��ZY system�����й���.
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../stdafx.h"

namespace ZYSystem {

	class MarketDataPane : public CView
	{
	public:
		MarketDataPane();

		CXTPPropertyGrid m_wndPropertyGrid;
		virtual ~MarketDataPane();

	protected:
		virtual void OnDraw(CDC* pDC); 

		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnSize(UINT nType, int cx, int cy);
		afx_msg void OnPanePropertiesCategorized();
		afx_msg void OnUpdatePanePropertiesCategorized(CCmdUI* pCmdUI);
		afx_msg void OnPanePropertiesAlphabetic();
		afx_msg void OnUpdatePanePropertiesAlphabetic(CCmdUI* pCmdUI);
		afx_msg void OnSetFocus(CWnd* pOldWnd);

		DECLARE_MESSAGE_MAP()
	};
}