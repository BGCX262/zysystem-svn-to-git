#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CIndexKDJ.h
///@brief 声明KDJ指标计算器
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../util/CMDBufferQueue.h"

#ifndef CINDEXKDJ_H_
#define CINDEXKDJ_H_

namespace ZYSystem {
	class CIndexKDJ
	{
	private:
		///@brief 上一日k值
		double last_k;

		///@brief 上一日d值
		double last_d;

		///@brief rsv随机变化率
		double rsv;

		///@brief 暂存行情数据队列的长度
		const static int MDQueueLength = 9;

		///@brief 需要暂存的行情队列
		CMDBufferQueue<SMarketData>* marketDataQueue;

		///@brief kdj指标计算结果落地
		CKDJWriter * dataSink;

	public:
		///@brief KDJ指标计算函数
		///@param in 用于计算的的最新行情数据
		///@return 计算完成的SKDJ值
		///@remark
		SKDJ calculate(SMarketData* in);

		///@brief KDJ指标计算器 构造函数
		///@param dataPath 用于计算的的最新行情数据
		///@remark
		CIndexKDJ(const TPath dataPath);
		~CIndexKDJ(void);
	};
}

#endif //CINDEXKDJ_H_