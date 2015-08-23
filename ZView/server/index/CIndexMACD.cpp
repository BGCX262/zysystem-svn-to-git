/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CIndexMACD.cpp
///@brief ʵ��MACDָ�������
///@author �ų�
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
    //12��ƽ��ϵ��
    L12 = 0.1538;
    //26��ƽ��ϵ��
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

    //���ü���ָ�������ʱ��,��ȷ������
    strcpy(ret.TradingDay,in->TradingDay);
    strcpy(ret.ExchangeID,in->ExchangeID);
    strcpy(ret.InstrumentID,in->InstrumentID); 
    strcpy(ret.UpdateTime,in->UpdateTime);
    ret.UpdateMillisec = in->UpdateMillisec;

    //����ָ��
    //ʮ����ָ��ƽ��ֵ��12��EMA��=L12����������ָ�� + 11/��12+1�������յ�12��EMA 
    double EMA12 = 0;
    EMA12 = L12 * in->LastPrice + (1 - L12) * last_12EMA;


    //��ʮ����ָ��ƽ��ֵ��26��EMA��=L26����������ָ�� + 25/��26+1�������յ�26��EMA 
    double EMA26 = 0;
    EMA26 = L26 * in->LastPrice + (1 - L26) * last_26EMA;
    
    //�����ʣ�DIF��=12��EMA-26��EMA
    ret.Idx_diff = EMA12 - EMA26;
    
    //����DIFƽ���ƶ�ƽ��ֵ��DEA��=���յ�DIF��0.2 +���յ�DEA��0.8
    ret.Idx_dea = ret.Idx_diff * 0.2 + last_dea * 0.8;
    last_dea = ret.Idx_dea;
    last_26EMA = EMA26;
    last_12EMA = EMA12;
    
    //��״�ߣ�BAR����BAR=2����DIF-DEA��
    ret.Idx_bar = (ret.Idx_diff - ret.Idx_dea) * 2;

    //���������
    dataSink->addRecord(&ret);
    return ret;
}

#endif //CINDEXMACD_CPP_
