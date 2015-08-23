/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CConfigXml.h
///@brief 程序化交易的配置文件读取器 
///@author 张弛
///@date 20110329
/////////////////////////////////////////////////////////////////////////
#pragma once
#include "CXML.h"

#ifndef CConfigXml_H_
#define CConfigXml_H_

namespace ZYSystem {
	class CConfigXml : public CXML {
		private:

		public:
			///@brief 获得要使用的服务器id
			///@param conn_id_in 服务器id，实际指配置中的connection的conn_id
			void getServerId(TConnectionID conn_id_in);
			
			///@brief 获得日志配置信息
			///@param logConfig_in 日志配置信息
			void getLogConfig(SLogConfig* logConfig_in);

			///@brief 获得合约
			///@param LogPath 日志路径
			void getInstruments(TInstrumentIDs instruments_in);

			///@brief 获得数据文件路径
			///@param data_path_in 数据路径
			void getDataPath(TPath data_path_in);

			///@brief 计算配置文件里投资者的数量
			///@return 投资者数量
			TVolume countInvestor();
			
			///@brief 计算配置文件里连接配置的数量
			///@return 连接配置数量
			TVolume countConnConfig();
			
			///@brief 计算配置文件模型的数量
			///@return 连接模型数量
			TVolume countModel();

			///@brief 获取指定序号的投资者
			///@param id 投资者序号
			///@param investor 投资者结构体
			///@return	投资者结构体
			TID getInvestor(TID id,SInvestor* investor);

			///@brief 获取风险控制管理器配置
			///@param riskControler Risk Controler Struct
			///@return	错误码
			TID getRiskControler(SRiskControler* riskControler);
		
			///@brief 获取指定序号的连接配置
			///@param id 连接序号
			///@param config 行情提供配置
			///@return	连接连接配置结构体
			TID getConnConfig(TConnectionID id,SMarketDataProvider* config);
			
			///@brief 获取指定序号的模型配置
			///@param id	模型序号
			///@param model	连接序号
			///@return 获取模型状态
			TID getModel(TID id,SModelConfigA* model);

			///@brief 获取重演的可用资金
			///@return 可用资金
			TMoney getRepeatAvailableFund();

			///@brief 获取配置中定义的系统运行模式
			TRunModel getRunModel();

			///@brief CConfigXml构造函数
			///@param configFile	配置文件路径
			CConfigXml(const TFile configFile);
			
			///@brief CConfigXml析构函数
			~CConfigXml(void);
	};
}

#endif //CConfigXml_H_
