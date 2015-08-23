/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CIndexKDJ.cpp
///@brief 实现KDJ指标计算器
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "CIndexKDJ.h"

#ifndef CINDEXKDJ_CPP_
#define CINDEXKDJ_CPP_

using namespace ZYSystem;

CIndexKDJ::CIndexKDJ(const TPath dataPath)
{
	this->dataSink = new CKDJWriter(dataPath);

	this->last_d = 50;
	this->last_k = 50;
	this->rsv = 0;

	marketDataQueue = new CMDBufferQueue<SMarketData>(9);
}


CIndexKDJ::~CIndexKDJ(void)
{
}

SKDJ CIndexKDJ::calculate(SMarketData* in)
{
	//先把来的行情送入行情队列
	marketDataQueue->push(in);

	SKDJ ret;

	//设置计算指标的行情时间,精确到毫秒
	strcpy(ret.TradingDay,in->TradingDay);
	strcpy(ret.ExchangeID,in->ExchangeID);
	strcpy(ret.InstrumentID,in->InstrumentID);
	strcpy(ret.UpdateTime,in->UpdateTime);
	ret.UpdateMillisec = in->UpdateMillisec;

	//准备足够的行情数据?
	if (marketDataQueue->getSize() != MDQueueLength) {
	
		//不够,那么置0就可以了
		ret.Idx_d = 0;
		ret.Idx_j = 0;
		ret.Idx_k = 0;
	
	} else {
		
		SMarketData lastMarketData;
		marketDataQueue->assembleMD(&lastMarketData);

		//计算指标
		//n日RSV=（Cn－Ln）÷（Hn－Ln）×100 　　
		//公式中，Cn为第n日收盘价；Ln为n日内的最低价；Hn为n日内的最高价。RSV值始终在1—100间波动。 
		//行情中可能存在不波动的情况,这时高低价是相等的
		if (lastMarketData.HighestPrice - lastMarketData.LowestPrice < 0.001) {
			rsv = 1;
		} else {
			rsv = (lastMarketData.LastPrice - lastMarketData.LowestPrice) 
				/ (lastMarketData.HighestPrice - lastMarketData.LowestPrice)
				* 100;
		}

		//当日K值=2/3×前一日K值+1/3×当日RSV
		ret.Idx_k = last_k * 2 / 3 + rsv /3;
		last_k = ret.Idx_k;

		//当日D值=2/3×前一日D值+1/3×当日K值
		ret.Idx_d = last_d * 2 / 3 + ret.Idx_k /3;
		last_d = ret.Idx_d;

		//J值=3*当日K值-2*当日D值
		ret.Idx_j = 3*ret.Idx_k - 2*ret.Idx_d;

		//为了下一次行情的到来,把不需要的行情数据清理出队列
		SMarketData x = SMarketData();
		marketDataQueue->pop(&x);

		//计算结果落地
		dataSink->addRecord(&ret);
	}

	return ret;
}
#endif //CINDEXKDJ_CPP_