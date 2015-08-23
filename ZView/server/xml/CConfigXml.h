/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CConfigXml.h
///@brief ���򻯽��׵������ļ���ȡ�� 
///@author �ų�
///@date 20110329
/////////////////////////////////////////////////////////////////////////
#pragma once
#include "CXML.h"

#ifndef CConfigXml_H_
#define CConfigXml_H_

namespace ZYSystem {
	class CConfigXml : public CXML {
		private:

		public:
			///@brief ���Ҫʹ�õķ�����id
			///@param conn_id_in ������id��ʵ��ָ�����е�connection��conn_id
			void getServerId(TConnectionID conn_id_in);
			
			///@brief �����־������Ϣ
			///@param logConfig_in ��־������Ϣ
			void getLogConfig(SLogConfig* logConfig_in);

			///@brief ��ú�Լ
			///@param LogPath ��־·��
			void getInstruments(TInstrumentIDs instruments_in);

			///@brief ��������ļ�·��
			///@param data_path_in ����·��
			void getDataPath(TPath data_path_in);

			///@brief ���������ļ���Ͷ���ߵ�����
			///@return Ͷ��������
			TVolume countInvestor();
			
			///@brief ���������ļ����������õ�����
			///@return ������������
			TVolume countConnConfig();
			
			///@brief ���������ļ�ģ�͵�����
			///@return ����ģ������
			TVolume countModel();

			///@brief ��ȡָ����ŵ�Ͷ����
			///@param id Ͷ�������
			///@param investor Ͷ���߽ṹ��
			///@return	Ͷ���߽ṹ��
			TID getInvestor(TID id,SInvestor* investor);

			///@brief ��ȡ���տ��ƹ���������
			///@param riskControler Risk Controler Struct
			///@return	������
			TID getRiskControler(SRiskControler* riskControler);
		
			///@brief ��ȡָ����ŵ���������
			///@param id �������
			///@param config �����ṩ����
			///@return	�����������ýṹ��
			TID getConnConfig(TConnectionID id,SMarketDataProvider* config);
			
			///@brief ��ȡָ����ŵ�ģ������
			///@param id	ģ�����
			///@param model	�������
			///@return ��ȡģ��״̬
			TID getModel(TID id,SModelConfigA* model);

			///@brief ��ȡ���ݵĿ����ʽ�
			///@return �����ʽ�
			TMoney getRepeatAvailableFund();

			///@brief ��ȡ�����ж����ϵͳ����ģʽ
			TRunModel getRunModel();

			///@brief CConfigXml���캯��
			///@param configFile	�����ļ�·��
			CConfigXml(const TFile configFile);
			
			///@brief CConfigXml��������
			~CConfigXml(void);
	};
}

#endif //CConfigXml_H_
