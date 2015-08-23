#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file HisConnector.h
///@brief ������ʷ��������������
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "Connector.h"
#include "../util/CTimeTranslator.h"

#ifndef CHISCONNECTOR_H_
#define CHISCONNECTOR_H_

namespace ZYSystem {
	class CHisConnector:public CConnector{
		private:
			///@brief ��������
		    CMDBufferQueue<SOrderReq> orderQueue;
            
            ///@brief ������������
            ///@param md_url �������ļ��л�ȡ�������ַ�ַ���
            ///@return 0Ϊͨ��,����ֵΪ����ԭ��
			TID getMd_url(TURL md_url);

			///@brief ������������
            ///@param md_url �������ļ��л�ȡ�Ľ��׵�ַ�ַ���
            ///@param investorID Ͷ���ߴ���
            ///@return 0Ϊͨ��,����ֵΪ����ԭ��
			TID getTd_url(TURL Td_url,TInvestorID investorID);

			///@brief �����ļ�����·��
			TPath basePath;

			///@brief ���ĵĺ�Լ�б�
			TInstrumentID instrumentSub;

			///@brief ��ʷ����
			TDate historyDate;

			///@brief ��������
			TDate tradingDay;
			
			///@brief ����ָ���������
			///@param instruments ��Ҫ���ĵ������Լ
			void getDayDataPath(TPath nowDatapath,TDate historyDate);
		public:
			///@brief ���ӵ�Զ�˵����������
			virtual void connect();
		
			///@brief ��Զ�˵�����������Ͽ�
			virtual void disconnect();
		
			///@brief ����ָ���������,����ģ�����ʷ���ݣ�ֻ֧�ֵ���Լ
			///@param instruments ��Ҫ���ĵ������Լ
			///@return 0Ϊͨ��,����ֵΪ����ԭ��
			virtual TID subscribeMarketData(SSubInstrument* instruments);

            ///@brief ����ָ���������
		    ///@param newOrder ��Ҫ���ĵ������Լ
			///@return 0Ϊͨ��,����ֵΪ����ԭ��
		    virtual TID newOrder(SOrderReq* newOrder);

			///@brief �յ�������
			///@param newMarketData ��Ҫ���ĵ������Լ
			virtual TID newMarketData(SMarketData* newMarketData);
		
			CHisConnector(SMarketDataProvider* in);
			~CHisConnector(void);
	};
}

#endif //CHISCONNECTOR_H_