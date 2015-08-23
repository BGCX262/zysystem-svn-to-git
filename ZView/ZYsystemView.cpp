/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.cpp
///@brief 主程序容器,用于执行Zy system的所有功能. 
///@author 张弛
///@date 20130818
/////////////////////////////////////////////////////////////////////////
#include "ZYsystemView.h"

using namespace ZYSystem;

IMPLEMENT_DYNCREATE(ZYsystemView, CView)

BEGIN_MESSAGE_MAP(ZYsystemView, CView)

END_MESSAGE_MAP()

// ZYsystemView construction/destruction

ZYsystemView::ZYsystemView()
{

}

ZYsystemView::~ZYsystemView()
{
}


void ZYsystemView::OnDraw(CDC* pDC) {

}

BOOL ZYsystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}