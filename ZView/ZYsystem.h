#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief ����������,����ִ��ZY system�����й���.
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "MainFrm.h"
#include "ZYsystemDoc.h"
#include "ChildFrame.h"
#include "ZYsystemView.h"

namespace ZYSystem {

	class ZYsystemApp : public CWinApp
	{
	public:
		ZYsystemApp();
		virtual BOOL InitInstance();
		afx_msg void OnAppAbout();
		DECLARE_MESSAGE_MAP()
	};

}
extern ZYSystem::ZYsystemApp theApp;