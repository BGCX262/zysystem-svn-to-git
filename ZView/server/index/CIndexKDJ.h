#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CIndexKDJ.h
///@brief ����KDJָ�������
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../util/CMDBufferQueue.h"

#ifndef CINDEXKDJ_H_
#define CINDEXKDJ_H_

namespace ZYSystem {
	class CIndexKDJ
	{
	private:
		///@brief ��һ��kֵ
		double last_k;

		///@brief ��һ��dֵ
		double last_d;

		///@brief rsv����仯��
		double rsv;

		///@brief �ݴ��������ݶ��еĳ���
		const static int MDQueueLength = 9;

		///@brief ��Ҫ�ݴ���������
		CMDBufferQueue<SMarketData>* marketDataQueue;

		///@brief kdjָ����������
		CKDJWriter * dataSink;

	public:
		///@brief KDJָ����㺯��
		///@param in ���ڼ���ĵ�������������
		///@return ������ɵ�SKDJֵ
		///@remark
		SKDJ calculate(SMarketData* in);

		///@brief KDJָ������� ���캯��
		///@param dataPath ���ڼ���ĵ�������������
		///@remark
		CIndexKDJ(const TPath dataPath);
		~CIndexKDJ(void);
	};
}

#endif //CINDEXKDJ_H_