#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTimeTranslator.h
///@brief ʱ��ת����ʽ��������,�������е�ʱ���ʽ��������ת��,����ģʽ
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#ifndef CTIMETRANSLATOR_H_
#define CTIMETRANSLATOR_H_

#include "../generate/Gen.h"

namespace ZYSystem {
    
    class CTimeTranslator
    {
        private:
            ///@brief ���ڸ�ʽ���� YYYYMMDD
            boost::gregorian::date_input_facet* date_input_formatter;

            ///@brief ��ʱ���ʽ���� HH:MM:SS
            boost::posix_time::time_input_facet* time_input_formatter;
            
            ///@brief ����·��ʵ��
            static CTimeTranslator* instance;
           
            CTimeTranslator(void);

        public:
            ///@brief ��ȡʱ�����������ʽ����ʵ��
			///@return ʱ�����������ʽ����
			///@remark 
            static CTimeTranslator* getInstance();

            ///@brief �������е�Tradingday��updateTimeת����ptime
			///@param in ��������
			///@return ת�����ptime
			///@remark 
            boost::posix_time::ptime mdkToPtime(SMarketData* in);

			///@brief ��ȡ����������ַ���
			///@param today ����
			void getToday(TDate today);

            ~CTimeTranslator(void);
    };
}
#endif //CTIMETRANSLATOR_H_
