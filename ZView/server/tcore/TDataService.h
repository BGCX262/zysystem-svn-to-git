#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TDataService.h
///@brief ���� �������ݷ��������ṩTDataSet�ĸ��ֲ�ѯ�����롢���·�����֧�ֽ���ҵ��
///@author �ų�
///@date 20120124
/////////////////////////////////////////////////////////////////////////
#include "../generate/Gen.h"
#include "TDataSet.h"

#ifndef TDATASERVICE_H_
#define TDATASERVICE_H_

namespace ZYSystem {
	class TDataService
	{
	private:
		TDataSet dataSet;

	public:
		///@brief ���� ��Լ
		///@param instrument_in �ʽ�仯
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID instrumentAdd(SInstrument* instrument_in);

		///@brief ����instrumentID���� ��Լ����
		///@param instrument_in ��Լ
		///@param instrumentID ��Լ����
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID instrumentSelectByInstrumentID(SInstrument* instrument_in,TInstrumentID instrumentID);

		///@brief ���� Ͷ����
		///@param investor_in Ͷ����
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID investorAdd(SInvestor* investor_in);
		
		///@brief ���� ʵʱ�ʽ�
		///@param realFund_in ʵʱ�ʽ�
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID realFundAdd(SRealFund* realFund_in);

		///@brief ͨ��investorID���ҿͻ��ʽ�SRealFund
		///@param investorID Ͷ���ߴ���
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID realFundSelectByInvestorID(SRealFund* realFund_out,TInvestorID investorID);

		///@brief ���� �ֲ�
		///@param realPosition_in �ֲ�
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID realPositionAdd(SRealPosition* realPosition_in);

		///@brief ����investorID��instrumentID���� �ֲ�
		///@param realPositio_out �ֲ�
		///@param investorID Ͷ���ߴ���
		///@param instrumentID ��Լ����
		///@param direction �ֲַ���
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID realPositionSelectByInvestorIDInstrumentIDDirection(SRealPosition* realPosition_out,
																TInvestorID investorID,
																TInstrumentID instrumentID,
																TDirection direction);

		///@brief ����investorID,instrumentIDɾ�� �ֲ�
		///@param investorID Ͷ���ߴ���
		///@param instrumentID ��Լ����
		///@param direction �ֲַ���
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID realPositionDeleteByInvestorIDInstrumentIDDirection(TInvestorID investorID,
																TInstrumentID instrumentID,
																TDirection direction);

		///@brief ���� �ɽ�
		///@param trade_in �ɽ�
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID tradeAdd(STrade* trade_in);

		///@brief ���� ��������
		///@param orderReq_in ��������
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID orderReqChangeAdd(SOrderReq* orderReq_in);

		///@brief ͨ��localOrderID����orderReq
		///@param localOrderID Ͷ���ߴ���
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID orderReqSelectByLocalOrderID(SOrderReq* orderReq_out,TLocalOrderID localOrderID);

		///@brief ͨ��localOrderID ɾ�� orderReq
		///@param localOrderID Ͷ���ߴ���
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID orderReqDeleteByLocalOrderID(TLocalOrderID localOrderID);

		///@brief ���� ��֤����
		///@param marginRate_in ��֤����
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID marginRateAdd(SMarginRate* marginRate_in);

		///@brief ����investorID��instrumentID���� ��Լ��֤����
		///@param marginRate_out ��֤����
		///@param investorID Ͷ���ߴ���
		///@param instrumentID ��Լ����
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID marginRateSelectByInvestorIDInstrumentID(SMarginRate* marginRate_out,TInvestorID investorID,TInstrumentID instrumentID);

		///@brief ����investorID,instrumentIDɾ�� ��Լ��֤����
		///@param investorID Ͷ���ߴ���
		///@param instrumentID ��Լ����
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID marginRateDeleteByInvestorIDInstrumentID(TInvestorID investorID,TInstrumentID instrumentID);

		///@brief ���� ��������
		///@param feeRate_in ��������
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID feeRateAdd(SFeeRate* feeRate_in);

		///@brief ����investorID��instrumentID���� �ͻ���������
		///@param feeRate_in ��������
		///@param investorID Ͷ���ߴ���
		///@param instrumentID ��Լ����
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID feeRateSelectByInvestorIDInstrumentID(SFeeRate* feeRate_out,TInvestorID investorID,TInstrumentID instrumentID);

		///@brief ����investorID,instrumentIDɾ�� �ͻ���������
		///@param investorID Ͷ���ߴ���
		///@param instrumentID ��Լ����
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID feeRateDeleteByInvestorIDInstrumentID(TInvestorID investorID,TInstrumentID instrumentID);

		///@brief ���� �����ź�
		///@param singnal_in �����ź�
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID singnalAdd(SSingnal* singnal_in);

		///@brief ���� �ʽ�仯
		///@param moneyChange_in �ʽ�仯
		///@return 0Ϊͨ��,����ֵΪ����ԭ��
		TID moneyChangeAdd(SMoneyChange* moneyChange_in);

		TDataService();
		~TDataService();
	};

}

#endif //TDATASERVICE_H_