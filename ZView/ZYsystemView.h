#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief 主程序容器,用于执行ZY system的所有功能.
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "ZYsystemDoc.h"

namespace ZYSystem {

	class ZYsystemView : public CView
	{
	public:
		virtual ~ZYsystemView();

	protected:
		virtual void OnDraw(CDC* pDC); 
		virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

		ZYsystemView();

		DECLARE_MESSAGE_MAP()

		DECLARE_DYNCREATE(ZYsystemView)
	};
}