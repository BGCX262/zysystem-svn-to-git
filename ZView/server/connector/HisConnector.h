#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file HisConnector.h
///@brief 声明历史数据重演连接器
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "Connector.h"
#include "../util/CTimeTranslator.h"

#ifndef CHISCONNECTOR_H_
#define CHISCONNECTOR_H_

namespace ZYSystem {
	class CHisConnector:public CConnector{
		private:
			///@brief 报单队列
		    CMDBufferQueue<SOrderReq> orderQueue;
            
            ///@brief 解析行情配置
            ///@param md_url 从配置文件中获取的行情地址字符串
            ///@return 0为通过,其他值为错误原因
			TID getMd_url(TURL md_url);

			///@brief 解析交易配置
            ///@param md_url 从配置文件中获取的交易地址字符串
            ///@param investorID 投资者代码
            ///@return 0为通过,其他值为错误原因
			TID getTd_url(TURL Td_url,TInvestorID investorID);

			///@brief 数据文件基础路径
			TPath basePath;

			///@brief 订阅的合约列表
			TInstrumentID instrumentSub;

			///@brief 历史日期
			TDate historyDate;

			///@brief 交易日期
			TDate tradingDay;
			
			///@brief 订阅指定标地行情
			///@param instruments 需要订阅的行情合约
			void getDayDataPath(TPath nowDatapath,TDate historyDate);
		public:
			///@brief 连接到远端的行情服务器
			virtual void connect();
		
			///@brief 与远端的行情服务器断开
			virtual void disconnect();
		
			///@brief 订阅指定标地行情,对于模拟和历史重演，只支持单合约
			///@param instruments 需要订阅的行情合约
			///@return 0为通过,其他值为错误原因
			virtual TID subscribeMarketData(SSubInstrument* instruments);

            ///@brief 订阅指定标地行情
		    ///@param newOrder 需要订阅的行情合约
			///@return 0为通过,其他值为错误原因
		    virtual TID newOrder(SOrderReq* newOrder);

			///@brief 收到新行情
			///@param newMarketData 需要订阅的行情合约
			virtual TID newMarketData(SMarketData* newMarketData);
		
			CHisConnector(SMarketDataProvider* in);
			~CHisConnector(void);
	};
}

#endif //CHISCONNECTOR_H_