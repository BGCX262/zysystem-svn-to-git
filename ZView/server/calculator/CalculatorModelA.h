#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CCalModelA.h
///@brief ����ģ��A
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#ifndef CALULATORMODELA_H_
#define CALULATORMODELA_H_

#include "../index/CIndexKDJ.h"
#include "../index/CIndexMACD.h"
#include "../util/CTimeTranslator.h"
#include "CalculatorModel.h"

namespace ZYSystem {

    class CCalModelA:public CalculatorModel
    {   
        private:
			
			///@brief ����ʱ��ת��ϵ��,���ƶ���ʱ�����һ������;
            boost::posix_time::time_duration calculateCycle;

			///@brief ������Ϣ
			SModelConfigA config;
		
	        ///@brief ����ת��������
            SMarketData afterCycle;

            ///@brief KDJָ�������
            CIndexKDJ* indexKDJ;

            ///@brief MACDָ�������
            CIndexMACD* indexMACD;

            ///@brief �ϴδ���ѭ��ʱ��
            boost::posix_time::ptime lastCycleTime;

			///@brief ʱ��ת����
			CTimeTranslator* timeTranslator;

            ///@brief ������������
			CMarketDataWriter* maketDataCycle;

			///@brief ��һ�ε�macd��kdj����ֵ
			SKDJ last_kdj;
			SMACD last_macd;

			///@brief ���ε�macd��kdj����ֵ
			SKDJ tmp_kdj;
			SMACD tmp_macd;

			///@brief ����kdj��macd�ı仯�ó�����ָ��
			///@param in ��������
			///@remark
			void getOrder(SMarketData* in);
			
			///@brief ���ֻ���ƽ�����ڿ�����
			TDirection direction;
        public:
            ///@brief ��������
			///@param in ��������
			///@remark 
            TID recivieMarketData(SSingnal* singnal_in,SMarketData* marketdata_in);

            ///@brief ����ʱ���
            int calculatorTime;

			///@brief ģ��A����
			///@param config ģ��A����
            CCalModelA(SModelConfigA config);

			///@brief ģ��A����
            ~CCalModelA(void);
    };
}
#endif //CALULATORMODELA_H_