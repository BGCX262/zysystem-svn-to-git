#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CCalModelA.h
///@brief 声明 计算模型抽象类
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#ifndef CALCULATORMODEL_H_
#define CALCULATORMODEL_H_

#include "../dataRoute/TEndPoint.h"

namespace ZYSystem {

    class CalculatorModel:public CTEndPoint
    {   
        public:
            ///@brief 接收数据
			///@param in 行情数据
			///@remark 
            virtual TID recivieMarketData(SSingnal* singnal_in,SMarketData* marketdata_in) = 0;

			///@brief 模型构造
            CalculatorModel(void);

			///@brief 模型析构
            ~CalculatorModel(void);
    };
}
#endif //CALCULATORMODEL_H_