/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CIndexMACD.cpp
///@brief 实现MACD指标计算器
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "CIndexMACD.h"

#ifndef CINDEXMACD_CPP_
#define CINDEXMACD_CPP_

using namespace ZYSystem;

CIndexMACD::CIndexMACD(const TPath dataPath)
{
    this->dataSink = new CMACDWriter(dataPath);
    last_dea = 0;
    //12日平滑系数
    L12 = 0.1538;
    //26日平滑系数
    L26 = 0.0741; 
	last_12EMA = 0;
	last_26EMA = 0;
}


CIndexMACD::~CIndexMACD(void)
{
}

SMACD CIndexMACD::calculate(SMarketData* in)
{
    SMACD ret;

    //设置计算指标的行情时间,精确到毫秒
    strcpy(ret.TradingDay,in->TradingDay);
    strcpy(ret.ExchangeID,in->ExchangeID);
    strcpy(ret.InstrumentID,in->InstrumentID); 
    strcpy(ret.UpdateTime,in->UpdateTime);
    ret.UpdateMillisec = in->UpdateMillisec;

    //计算指标
    //十二日指数平均值（12日EMA）=L12×当日收盘指数 + 11/（12+1）×昨日的12日EMA 
    double EMA12 = 0;
    EMA12 = L12 * in->LastPrice + (1 - L12) * last_12EMA;


    //二十六日指数平均值（26日EMA）=L26×当日收盘指数 + 25/（26+1）×昨日的26日EMA 
    double EMA26 = 0;
    EMA26 = L26 * in->LastPrice + (1 - L26) * last_26EMA;
    
    //差离率（DIF）=12日EMA-26日EMA
    ret.Idx_diff = EMA12 - EMA26;
    
    //九日DIF平滑移动平均值（DEA）=当日的DIF×0.2 +昨日的DEA×0.8
    ret.Idx_dea = ret.Idx_diff * 0.2 + last_dea * 0.8;
    last_dea = ret.Idx_dea;
    last_26EMA = EMA26;
    last_12EMA = EMA12;
    
    //柱状线（BAR）：BAR=2×（DIF-DEA）
    ret.Idx_bar = (ret.Idx_diff - ret.Idx_dea) * 2;

    //计算结果落地
    dataSink->addRecord(&ret);
    return ret;
}

#endif //CINDEXMACD_CPP_
