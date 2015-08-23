#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file DataFile.h
///@brief 数据文件访问基类
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#include "../generate/TypeDefine.h"

#ifndef CDATAFILE_H_
#define CDATAFILE_H_

namespace ZYSystem {

	class CDataFile
	{
	public:
        ///@brief 全局共享数据文件存储路径
		static TPath dataPath;
		
        ///@brief 构造函数
        CDataFile(void);
		
        ///@brief 析构函数
        ~CDataFile(void);
	};
}
#endif //CDATAFILE_H_
