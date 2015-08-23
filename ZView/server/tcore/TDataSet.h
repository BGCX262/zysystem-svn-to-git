#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TDataSet.h
///@brief ���� �������ݼ��ϣ����ڴ洢���ֽ������ݼ��ϡ�
///@author �ų�
///@date 20120124
/////////////////////////////////////////////////////////////////////////
#include "../generate/Gen.h"

#ifndef TDATASET_H_
#define TDATASET_H_

namespace ZYSystem {
	class TDataSet
	{
	public:
		///@brief ��Լ��Ϣ
		std::vector<SInstrument> instruments;

		///@brief �ͻ��˺�
		std::vector<SInvestor> investors;

		///@brief �ͻ�ʵʱ�ʽ�
		std::vector<SRealFund> realFunds;

		///@brief �ͻ��ֲ�
		std::vector<SRealPosition> realPositions;

		///@brief �ͻ��ɽ�
		std::vector<STrade> trades;

		///@brief �ͻ�����
		std::vector<SOrderReq> orderReqs;

		///@brief �ͻ���֤����
		std::vector<SMarginRate> marginRates;

		///@brief �ͻ���������
		std::vector<SFeeRate> feeRates;

		///@brief �����ź�
		std::vector<SSingnal> singnals;

		///@brief �ʽ�仯��Ϣ
		std::vector<SMoneyChange> moneyChanges;
		
		TDataSet();
		~TDataSet();
	};
}

#endif //TDATASET_H_