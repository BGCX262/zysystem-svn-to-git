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

	class SignarPane : public CView
	{
	public:
		CXTPListCtrl m_listCtrl;

		SignarPane();
		virtual ~SignarPane();

	protected:
		virtual void OnDraw(CDC* pDC); 

		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnSize(UINT nType, int cx, int cy);
		afx_msg void OnSetFocus(CWnd* pOldWnd);

		DECLARE_MESSAGE_MAP()
	};
}
