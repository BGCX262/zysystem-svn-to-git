#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief 主程序容器,用于执行ZY system的所有功能.
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"
#include "ZYsystem.h"

namespace ZYSystem {

	class ZYsystemDoc : public CDocument
	{
	protected: // create from serialization only
		ZYsystemDoc();
		DECLARE_DYNCREATE(ZYsystemDoc)

	public:
		virtual BOOL OnNewDocument();
		virtual void Serialize(CArchive& ar);
		virtual ~ZYsystemDoc();

	protected:
		DECLARE_MESSAGE_MAP()
	};
}