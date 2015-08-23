#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file MDOnlyConnector.h
///@brief 声明 仅用于行情接收的连接器
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "Connector.h"
#include "../ctpSpi/CtpMDSpi.h"

#ifndef CMDONLYCONNECTOR_H_
#define CMDONLYCONNECTOR_H_

namespace ZYSystem {
	class CMDOnlyConnector:public CConnector
	{
	public:

		///@brief 连接到远端的行情服务器
		virtual void connect();

		///@brief 与远端的行情服务器断开
		virtual void disconnect();
	
		///@brief 订阅指定标地行情
		///@param instruments 需要订阅的行情合约
		virtual TID subscribeMarketData(SSubInstrument* instruments);

        ///@brief 订阅指定标地行情
		///@param SOrder 需要订阅的行情合约
		virtual TID newOrder(SOrderReq* newOrder);

		///@brief 收到新行情
		///@param SOrder 需要订阅的行情合约
		virtual TID newMarketData(SMarketData* newMarketData);

		///@brief CMDOnlyConnector 构造函数
		///@param config 行情提供者配置信息
		CMDOnlyConnector(SMarketDataProvider* config);
		
		///@brief CMDOnlyConnector 析构函数
		~CMDOnlyConnector();
	private:
		///@brief CTP行情服务
		CtpMDSpi* ctpMDSpi;
	
		///@brief 配置
		SInvestor *investor;
	};
}

#endif //CMDONLYCONNECTOR_H