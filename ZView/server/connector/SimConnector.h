#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file SimConnector.h
///@brief 声明行情模拟交易连接器
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "Connector.h"
#include "../ctpSpi/CtpMDSpi.h"

#ifndef CSIMCONNECTOR_H_
#define CSIMCONNECTOR_H_

namespace ZYSystem {

	class CSimConnector:public CConnector
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
		///@param newOrder 需要订阅的行情合约
		virtual TID newOrder(SOrderReq* newOrder);

		///@brief 收到新行情
		///@param newMarketData 需要订阅的行情合约
		virtual TID newMarketData(SMarketData* newMarketData);
		
		///@brief CSimConnector 构造函数
		///@param *config 行情提供者配置信息
		CSimConnector(SMarketDataProvider *config);
		
		///@brief CSimConnector 析构函数
		~CSimConnector();
	private:
		///@brief CTP行情服务
		CtpMDSpi* ctpMDSpi;

		///@brief 行情落地
		CMarketDataWriter* marketDataWriter;
	};
}

#endif //CSIMCONNECTOR_H_