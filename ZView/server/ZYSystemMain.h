#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.h
///@brief ����������,����ִ��ZY system�����й���.
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#include "./connector/ASPConnector.h"
#include "./connector/HisConnector.h"
#include "./connector/MDOnlyConnector.h"
#include "./connector/SimConnector.h"

#include "./calculator/CalculatorModel.h"
#include "./calculator/CalculatorModelA.h"

#include "./tcore/TCore.h"

#include "./xml/CConfigXml.h"

#ifndef ZYSYSTEMMAIN_H_
#define ZYSYSTEMMAIN_H_

namespace ZYSystem {
	class ZYSystemMain {
		private:
			///@brief ���׺���
			TCore* tCore;

			///@brief ����ģ��A
			CalculatorModel* modelA;

			///@brief Ͷ��������
			SInvestor* investorMap;

			///@brief ģ������
			SModelConfigA* modelMap;

			///@brief ��ȡͶ���߶���
			////@param *in	���ҵ�Ͷ���ߴ���
			////@param *ret	���ص�Ͷ����
			SInvestor* getInvestorByInvestorId(char *in,SInvestor *ret);

			///@brief ϵͳ�����ļ�
			CConfigXml* configXML;

			///@brief Ҫ���յĺ�Լ����
			TVolume instrumentINT;

			///@brief ����ת����
			CDataRoute* dataRoute;

			///@brief ������������� 
			///@param *config	�������õ�SConnectionConfig
			///@return			���سɹ�ָ�����������,���򷵻�flase
			bool createMarketDataReceiver(SMarketDataProvider *config);

			///@brief ��ʼ��Ͷ����
			void initInvestor();

			///@brief ��ʼ��������
			void initConnector();

			///@brief ��ʼ�����׺���
			void initTCore();

			///@brief ��ʼ������
			void initModel();
		public:
			///@brief ZYSystemMain���캯��
			///@param *configXML_in	�����ļ�
			ZYSystemMain(CConfigXml *configXML_in);
			
			///@brief ZYSystemMain��������
			~ZYSystemMain(void);
	};
}

#endif // ZYSYSTEMMAIN_H_
