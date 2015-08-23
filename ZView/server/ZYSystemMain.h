#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief 主程序容器,用于执行ZY system的所有功能.
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#include "./connector/ASPConnector.h"
#include "./connector/HisConnector.h"
#include "./connector/MDOnlyConnector.h"
#include "./connector/SimConnector.h"

#include "./calculator/CalculatorModel.h"
#include "./calculator/CalculatorModelA.h"

#include "./tcore/TCore.h"

#include "./xml/CConfigXml.h"

#ifndef ZYSYSTEMMAIN_H_
#define ZYSYSTEMMAIN_H_

namespace ZYSystem {
	class ZYSystemMain {
		private:
			///@brief 交易核心
			TCore* tCore;

			///@brief 计算模型A
			CalculatorModel* modelA;

			///@brief 投资者容器
			SInvestor* investorMap;

			///@brief 模型容器
			SModelConfigA* modelMap;

			///@brief 获取投资者对象
			////@param *in	查找的投资者代码
			////@param *ret	返回的投资者
			SInvestor* getInvestorByInvestorId(char *in,SInvestor *ret);

			///@brief 系统配置文件
			CConfigXml* configXML;

			///@brief 要接收的合约数量
			TVolume instrumentINT;

			///@brief 行情转发器
			CDataRoute* dataRoute;

			///@brief 创建行情服务器 
			///@param *config	包含配置的SConnectionConfig
			///@return			加载成功指定的行情服务,否则返回flase
			bool createMarketDataReceiver(SMarketDataProvider *config);

			///@brief 初始化投资者
			void initInvestor();

			///@brief 初始化连接器
			void initConnector();

			///@brief 初始化交易核心
			void initTCore();

			///@brief 初始化行情
			void initModel();
		public:
			///@brief ZYSystemMain构造函数
			///@param *configXML_in	配置文件
			ZYSystemMain(CConfigXml *configXML_in);
			
			///@brief ZYSystemMain析构函数
			~ZYSystemMain(void);
	};
}

#endif // ZYSYSTEMMAIN_H_
