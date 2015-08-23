
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CDataRoute.h
///@brief ����·������,���𽫽��յ�����������ת������������������ص��ļ�,����ģʽ
///       ��ʵ����һ��ϵͳ�ڲ����е���Ϣ���ߣ���ͨ��������
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:13.962Z
/////////////////////////////////////////////////////////////////////////
#include "CTPackageFactory.h"
#include "MsgQueue.h"

#ifndef CDATAROUTE_H_
#define CDATAROUTE_H_

namespace ZYSystem {

	class CDataRoute
	{
		private:    
   
      ///@brief ��־��Ϣ��ת����
  		boost::signals2::signal<TID (SLog*)> sig_SLog;
   
      ///@brief �����ṩ�߰�ת����
  		boost::signals2::signal<TID (SMarketDataProvider*)> sig_SMarketDataProvider;
   
      ///@brief Ͷ���߰�ת����
  		boost::signals2::signal<TID (SInvestor*)> sig_SInvestor;
   
      ///@brief �����ת����
  		boost::signals2::signal<TID (SMarketData*)> sig_SMarketData;
   
      ///@brief KDJָ���ת����
  		boost::signals2::signal<TID (SKDJ*)> sig_SKDJ;
   
      ///@brief MACDָ���ת����
  		boost::signals2::signal<TID (SMACD*)> sig_SMACD;
   
      ///@brief ����ģ��A���ð�ת����
  		boost::signals2::signal<TID (SModelConfigA*)> sig_SModelConfigA;

      COrderReqWriter* OrderReqW;
               
      ///@brief ���������ת����
  		boost::signals2::signal<TID (SOrderReq*)> sig_SOrderReq;

      CTradeWriter* TradeW;
               
      ///@brief �ɽ���ת����
  		boost::signals2::signal<TID (STrade*)> sig_STrade;
   
      ///@brief ���в�λ��ת����
  		boost::signals2::signal<TID (SRealPosition*)> sig_SRealPosition;
   
      ///@brief �����ʽ��ת����
  		boost::signals2::signal<TID (SRealFund*)> sig_SRealFund;
   
      ///@brief ���ĵĺ�Լ����ת����
  		boost::signals2::signal<TID (SSubInstrument*)> sig_SSubInstrument;

      CSingnalWriter* SingnalW;
               
      ///@brief �����źŰ�ת����
  		boost::signals2::signal<TID (SSingnal*)> sig_SSingnal;
   
      ///@brief ��Լ��ת����
  		boost::signals2::signal<TID (SInstrument*)> sig_SInstrument;
   
      ///@brief ���չ�������ת����
  		boost::signals2::signal<TID (SRiskControler*)> sig_SRiskControler;
   
      ///@brief ������ת����
  		boost::signals2::signal<TID (SMoneyChange*)> sig_SMoneyChange;
   
      ///@brief �½����հ�ת����
  		boost::signals2::signal<TID (SNewTradingDay*)> sig_SNewTradingDay;

      COrderRspWriter* OrderRspW;
               
      ///@brief ������Ӧ��ת����
  		boost::signals2::signal<TID (SOrderRsp*)> sig_SOrderRsp;
   
      ///@brief ��Լ��֤���ʰ�ת����
  		boost::signals2::signal<TID (SMarginRate*)> sig_SMarginRate;
   
      ///@brief ��Լ�������ʰ�ת����
  		boost::signals2::signal<TID (SFeeRate*)> sig_SFeeRate;
   
      ///@brief ��־������Ϣ��ת����
  		boost::signals2::signal<TID (SLogConfig*)> sig_SLogConfig;

			///@brief ת������
			CMsgQueue* queue;
      
      ///@brief ������
      boost::function0<void> connectConnector;

      ///@brief ����ת������
			CMsgQueue* MDqueue;

			///@brief ����·��ʵ��
			static CDataRoute* instance;

			///@brief ��������
			CTPackageFactory packageFactory;
			
			CDataRoute(void);
		public:
			///@brief �����ӿ� 
			///@param in ��������·�ɰ�
			void send(CTPackage* in);
      
      ///@brief ��������������connnection
      ///@param f ����
  		void setConnector(boost::function0<void> connectConnector_in);


      ///@brief ������־��Ϣ
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SLog*)> f);

      ///@brief ���������ṩ��
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SMarketDataProvider*)> f);

      ///@brief ����Ͷ����
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SInvestor*)> f);

      ///@brief ��������
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SMarketData*)> f);

      ///@brief ����KDJָ��
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SKDJ*)> f);

      ///@brief ����MACDָ��
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SMACD*)> f);

      ///@brief ���ļ���ģ��A����
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SModelConfigA*)> f);

      ///@brief ���ı�������
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SOrderReq*)> f);

      ///@brief ���ĳɽ�
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (STrade*)> f);

      ///@brief �������в�λ
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SRealPosition*)> f);

      ///@brief ���������ʽ�
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SRealFund*)> f);

      ///@brief ���Ķ��ĵĺ�Լ��
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SSubInstrument*)> f);

      ///@brief ���Ľ����ź�
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SSingnal*)> f);

      ///@brief ���ĺ�Լ
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SInstrument*)> f);

      ///@brief ���ķ��չ�����
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SRiskControler*)> f);

      ///@brief ���ĳ����
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SMoneyChange*)> f);

      ///@brief �����½�����
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SNewTradingDay*)> f);

      ///@brief ���ı�����Ӧ
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SOrderRsp*)> f);

      ///@brief ���ĺ�Լ��֤����
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SMarginRate*)> f);

      ///@brief ���ĺ�Լ��������
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SFeeRate*)> f);

      ///@brief ������־������Ϣ
      ///@param f ���ĵķ���
  		void subscribe(boost::function<TID (SLogConfig*)> f);

               
			///@brief �����ӿ� 
			///@param in ��������·�ɰ�
			///@param f ���ĵķ���
			void startup();

			///@brief ��ȡ����·��ʵ��
			///@return ����·��
			static CDataRoute* getInstance();

			///@brief CDataRoute����
      ~CDataRoute(void);
	};
}
#endif //CDATAROUTE_H_
		