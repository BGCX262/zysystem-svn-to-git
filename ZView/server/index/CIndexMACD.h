#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CIndexMACD.h
///@brief 声明MACD指标计算器 
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../generate/Gen.h"

#ifndef CINDEXMACD_H_
#define CINDEXMACD_H_

namespace ZYSystem {

	class CIndexMACD
	{  
	private:
		///@brief 12日平滑系数
		double L12;

		///@brief 26日平滑系数
		double L26;

		///@brief 昨12日EMA
		double last_12EMA;

		///@brief 昨26日EMA
		double last_26EMA;

		///@brief 昨dea
		double last_dea;

		///@brief kdj指标计算结果落地
		CMACDWriter* dataSink;
	public:
		///@brief KDJ指标计算函数
		///@param in 用于计算的的最新行情数据
		///@return 计算完成的SKDJ值
		///@remark
		SMACD calculate(SMarketData* in);

		///@brief MACD指标计算器 构造函数
		///@param dataPath 用于计算的的最新行情数据
		///@remark
		CIndexMACD(const TPath dataPath);
		~CIndexMACD(void);
	};   
}

#endif //CINDEXMACD_H_