/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CIndexKDJ.cpp
///@brief ʵ��KDJָ�������
///@author �ų�
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
	//�Ȱ��������������������
	marketDataQueue->push(in);

	SKDJ ret;

	//���ü���ָ�������ʱ��,��ȷ������
	strcpy(ret.TradingDay,in->TradingDay);
	strcpy(ret.ExchangeID,in->ExchangeID);
	strcpy(ret.InstrumentID,in->InstrumentID);
	strcpy(ret.UpdateTime,in->UpdateTime);
	ret.UpdateMillisec = in->UpdateMillisec;

	//׼���㹻����������?
	if (marketDataQueue->getSize() != MDQueueLength) {
	
		//����,��ô��0�Ϳ�����
		ret.Idx_d = 0;
		ret.Idx_j = 0;
		ret.Idx_k = 0;
	
	} else {
		
		SMarketData lastMarketData;
		marketDataQueue->assembleMD(&lastMarketData);

		//����ָ��
		//n��RSV=��Cn��Ln���£�Hn��Ln����100 ����
		//��ʽ�У�CnΪ��n�����̼ۣ�LnΪn���ڵ���ͼۣ�HnΪn���ڵ���߼ۡ�RSVֵʼ����1��100�䲨���� 
		//�����п��ܴ��ڲ����������,��ʱ�ߵͼ�����ȵ�
		if (lastMarketData.HighestPrice - lastMarketData.LowestPrice < 0.001) {
			rsv = 1;
		} else {
			rsv = (lastMarketData.LastPrice - lastMarketData.LowestPrice) 
				/ (lastMarketData.HighestPrice - lastMarketData.LowestPrice)
				* 100;
		}

		//����Kֵ=2/3��ǰһ��Kֵ+1/3������RSV
		ret.Idx_k = last_k * 2 / 3 + rsv /3;
		last_k = ret.Idx_k;

		//����Dֵ=2/3��ǰһ��Dֵ+1/3������Kֵ
		ret.Idx_d = last_d * 2 / 3 + ret.Idx_k /3;
		last_d = ret.Idx_d;

		//Jֵ=3*����Kֵ-2*����Dֵ
		ret.Idx_j = 3*ret.Idx_k - 2*ret.Idx_d;

		//Ϊ����һ������ĵ���,�Ѳ���Ҫ�������������������
		SMarketData x = SMarketData();
		marketDataQueue->pop(&x);

		//���������
		dataSink->addRecord(&ret);
	}

	return ret;
}
#endif //CINDEXKDJ_CPP_