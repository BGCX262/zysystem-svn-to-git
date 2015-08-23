#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CCalModelA.h
///@brief ���� ����ģ�ͳ�����
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#ifndef CALCULATORMODEL_H_
#define CALCULATORMODEL_H_

#include "../dataRoute/TEndPoint.h"

namespace ZYSystem {

    class CalculatorModel:public CTEndPoint
    {   
        public:
            ///@brief ��������
			///@param in ��������
			///@remark 
            virtual TID recivieMarketData(SSingnal* singnal_in,SMarketData* marketdata_in) = 0;

			///@brief ģ�͹���
            CalculatorModel(void);

			///@brief ģ������
            ~CalculatorModel(void);
    };
}
#endif //CALCULATORMODEL_H_