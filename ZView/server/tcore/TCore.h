#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TCore.h
///@brief ���� ���׺���,ʵ�ָ��ֽ���ҵ��ͬʱҲ�������ò��Դ������
///@author �ų�
///@date 20130512
/////////////////////////////////////////////////////////////////////////
#include "../dataRoute/TEndPoint.h"
#include "TDataService.h"

#ifndef TCORE_H_
#define TCORE_H_


namespace ZYSystem {
	class TCore:public CTEndPoint
	{
	private:
		///@brief ���ݷ���
		TDataService tDataService;

	public:
		///@brief �ʽ�仯����
		///@param moneyChange_in �ʽ�仯
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID changeFund(SMoneyChange* moneyChange_in);

		///@brief ������
		///@param marketData_in ����仯
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID newMarketData(SMarketData* marketData_in);

		///@brief �³ɽ�
		///@param trade_in �ɽ��ر�
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID newTrade(STrade* trade_in);

		///@brief �±�����Ӧ
		///@param orderRsp_in ������Ӧ
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID newOrderRespone(SOrderRsp* orderRsp_in);

		///@brief ����������
		///@param feeRate_in ������
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID newFeeRate(SFeeRate* feeRate_in);

		///@brief �±�֤����
		///@param marginRate_in ������
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID newMarginRate(SMarginRate* marginRate_in);

		///@brief �����˻����ڳ���ʼ����������ǰ������
		///@param money_in ������
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID createInvestor(SInvestor* investor_in);

		///@brief ����
		///@remark
		TCore();
		~TCore();
	};
}

#endif //TCORE_H_