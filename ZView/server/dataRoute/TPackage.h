#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TPackage.h
///@brief 系统数据路由的传输包声明,将各个处理单元的注册到数据路由的接口统一
///@author 张弛
///@date 20120303
/////////////////////////////////////////////////////////////////////////
#include "../generate/gen.h"

#ifndef CTPACKAGE_H_
#define CTPACKAGE_H_

namespace ZYSystem {
	class CTPackage
	{
	private:
		///@brief 数据包的内容类型
		TPID packageType;

		///@brief 数据包内容
		char* content;

		///@brief 数据包长度
		TPLength length;
	public:
		///@brief 设置数据包内容类型
		///@param type 类型
		void setPackageType(TPID type);

		///@brief 获取数据包内容类型
		///@return	类型
		TPID getPackageType();

		///@brief 设置数据包传递的信息内容
		///@param in 内容指针
		///@param length 内容长度
		TID setContent(void* content_in,TPLength length_in);

		///@brief 获取数据包的内容
		///@param in 获取信息的指针，非空
		///@param length 内容长度
		TID getContent(void* content_in);

		///@brief 计算行情队列中的开盘\最低\最高\收盘
		CTPackage(void);

		///@brief TPackage的析构函数
		~CTPackage(void);
	};
}
#endif //CTPACKAGE_H_