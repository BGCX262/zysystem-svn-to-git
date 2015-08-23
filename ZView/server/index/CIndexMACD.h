#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CIndexMACD.h
///@brief ����MACDָ������� 
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../generate/Gen.h"

#ifndef CINDEXMACD_H_
#define CINDEXMACD_H_

namespace ZYSystem {

	class CIndexMACD
	{  
	private:
		///@brief 12��ƽ��ϵ��
		double L12;

		///@brief 26��ƽ��ϵ��
		double L26;

		///@brief ��12��EMA
		double last_12EMA;

		///@brief ��26��EMA
		double last_26EMA;

		///@brief ��dea
		double last_dea;

		///@brief kdjָ����������
		CMACDWriter* dataSink;
	public:
		///@brief KDJָ����㺯��
		///@param in ���ڼ���ĵ�������������
		///@return ������ɵ�SKDJֵ
		///@remark
		SMACD calculate(SMarketData* in);

		///@brief MACDָ������� ���캯��
		///@param dataPath ���ڼ���ĵ�������������
		///@remark
		CIndexMACD(const TPath dataPath);
		~CIndexMACD(void);
	};   
}

#endif //CINDEXMACD_H_