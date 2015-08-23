#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CCalModelA.h
///@brief 计算模型A
///@author 张弛
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
			
			///@brief 行情时间转换系数,控制多少时间计算一次行情;
            boost::posix_time::time_duration calculateCycle;

			///@brief 配置信息
			SModelConfigA config;
		
	        ///@brief 经过转换的行情
            SMarketData afterCycle;

            ///@brief KDJ指标计算器
            CIndexKDJ* indexKDJ;

            ///@brief MACD指标计算器
            CIndexMACD* indexMACD;

            ///@brief 上次处理循环时间
            boost::posix_time::ptime lastCycleTime;

			///@brief 时间转换器
			CTimeTranslator* timeTranslator;

            ///@brief 处理后行情落地
			CMarketDataWriter* maketDataCycle;

			///@brief 上一次的macd和kdj计算值
			SKDJ last_kdj;
			SMACD last_macd;

			///@brief 本次的macd和kdj计算值
			SKDJ tmp_kdj;
			SMACD tmp_macd;

			///@brief 根据kdj和macd的变化得出交易指令
			///@param in 行情数据
			///@remark
			void getOrder(SMarketData* in);
			
			///@brief 开仓或者平仓周期控制器
			TDirection direction;
        public:
            ///@brief 接收数据
			///@param in 行情数据
			///@remark 
            TID recivieMarketData(SSingnal* singnal_in,SMarketData* marketdata_in);

            ///@brief 计算时间差
            int calculatorTime;

			///@brief 模型A构造
			///@param config 模型A配置
            CCalModelA(SModelConfigA config);

			///@brief 模型A析构
            ~CCalModelA(void);
    };
}
#endif //CALULATORMODELA_H_