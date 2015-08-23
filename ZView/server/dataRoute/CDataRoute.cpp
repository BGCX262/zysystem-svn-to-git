
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CDataRoute.cpp
///@brief 数据路由实现,负责将接收到的行情数据转发到计算器和行情落地到文件
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:15.865Z
/////////////////////////////////////////////////////////////////////////
#include "CDataRoute.h"

#ifndef CDATAROUTE_CPP_
#define CDATAROUTE_CPP_

using namespace ZYSystem;

CDataRoute* CDataRoute::instance = NULL;

CDataRoute::CDataRoute(){
  packageFactory = CTPackageFactory();
  queue =new CMsgQueue(DATAROUTE_QUE_LEN);
  MDqueue =new CMsgQueue(DATAROUTE_MDQUE_LEN);
  OrderReqW = new COrderReqWriter(CDataFile::dataPath);
  TradeW = new CTradeWriter(CDataFile::dataPath);
  SingnalW = new CSingnalWriter(CDataFile::dataPath);
  OrderRspW = new COrderRspWriter(CDataFile::dataPath);
  
}

CDataRoute::~CDataRoute(void)
{
}

CDataRoute* CDataRoute::getInstance(){
	if (instance == NULL) {
		instance =new CDataRoute();
	}
	return instance;
}

void CDataRoute::send(CTPackage* in){
	if (in->getPackageType() == TPID_MarketData) {
		MDqueue->push(in);
	} else {
		queue->push(in);
	}
}

void CDataRoute::setConnector(boost::function0<void> connectConnector_in){
  connectConnector = connectConnector_in;
}


void CDataRoute::subscribe(boost::function<TID (SLog*)> f){
	sig_SLog.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SMarketDataProvider*)> f){
	sig_SMarketDataProvider.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SInvestor*)> f){
	sig_SInvestor.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SMarketData*)> f){
	sig_SMarketData.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SKDJ*)> f){
	sig_SKDJ.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SMACD*)> f){
	sig_SMACD.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SModelConfigA*)> f){
	sig_SModelConfigA.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SOrderReq*)> f){
	sig_SOrderReq.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (STrade*)> f){
	sig_STrade.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SRealPosition*)> f){
	sig_SRealPosition.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SRealFund*)> f){
	sig_SRealFund.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SSubInstrument*)> f){
	sig_SSubInstrument.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SSingnal*)> f){
	sig_SSingnal.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SInstrument*)> f){
	sig_SInstrument.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SRiskControler*)> f){
	sig_SRiskControler.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SMoneyChange*)> f){
	sig_SMoneyChange.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SNewTradingDay*)> f){
	sig_SNewTradingDay.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SOrderRsp*)> f){
	sig_SOrderRsp.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SMarginRate*)> f){
	sig_SMarginRate.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SFeeRate*)> f){
	sig_SFeeRate.connect(f);
}

void CDataRoute::subscribe(boost::function<TID (SLogConfig*)> f){
	sig_SLogConfig.connect(f);
}


void CDataRoute::startup(){

  boost::thread thrd(connectConnector);
	thrd.detach();

	CTPackage p = CTPackage();
	//1毫秒
	boost::posix_time::time_duration td = boost::posix_time::time_duration(0,0,1);
  void* s;
     
	while(1){ 
		//队列处理
	    while(MDqueue->getSize() != 0 || queue->getSize() != 0 ){    
            while(queue->getSize() != 0){
			    queue->pop(&p);

			    switch (p.getPackageType()) {                

                case TPID_Log: {
                  s =new SLog();
					        packageFactory.toStructs(&p,(SLog*) s);
                  
				          sig_SLog((SLog*)s);
				          break;
				    }

                case TPID_MarketDataProvider: {
                  s =new SMarketDataProvider();
					        packageFactory.toStructs(&p,(SMarketDataProvider*) s);
                  
				          sig_SMarketDataProvider((SMarketDataProvider*)s);
				          break;
				    }

                case TPID_Investor: {
                  s =new SInvestor();
					        packageFactory.toStructs(&p,(SInvestor*) s);
                  
				          sig_SInvestor((SInvestor*)s);
				          break;
				    }

                case TPID_KDJ: {
                  s =new SKDJ();
					        packageFactory.toStructs(&p,(SKDJ*) s);
                  
				          sig_SKDJ((SKDJ*)s);
				          break;
				    }

                case TPID_MACD: {
                  s =new SMACD();
					        packageFactory.toStructs(&p,(SMACD*) s);
                  
				          sig_SMACD((SMACD*)s);
				          break;
				    }

                case TPID_ModelConfigA: {
                  s =new SModelConfigA();
					        packageFactory.toStructs(&p,(SModelConfigA*) s);
                  
				          sig_SModelConfigA((SModelConfigA*)s);
				          break;
				    }

                case TPID_OrderReq: {
                  s =new SOrderReq();
					        packageFactory.toStructs(&p,(SOrderReq*) s);
                  OrderReqW->addRecord((SOrderReq*) s);
				          sig_SOrderReq((SOrderReq*)s);
				          break;
				    }

                case TPID_Trade: {
                  s =new STrade();
					        packageFactory.toStructs(&p,(STrade*) s);
                  TradeW->addRecord((STrade*) s);
				          sig_STrade((STrade*)s);
				          break;
				    }

                case TPID_RealPosition: {
                  s =new SRealPosition();
					        packageFactory.toStructs(&p,(SRealPosition*) s);
                  
				          sig_SRealPosition((SRealPosition*)s);
				          break;
				    }

                case TPID_RealFund: {
                  s =new SRealFund();
					        packageFactory.toStructs(&p,(SRealFund*) s);
                  
				          sig_SRealFund((SRealFund*)s);
				          break;
				    }

                case TPID_SubInstrument: {
                  s =new SSubInstrument();
					        packageFactory.toStructs(&p,(SSubInstrument*) s);
                  
				          sig_SSubInstrument((SSubInstrument*)s);
				          break;
				    }

                case TPID_Singnal: {
                  s =new SSingnal();
					        packageFactory.toStructs(&p,(SSingnal*) s);
                  SingnalW->addRecord((SSingnal*) s);
				          sig_SSingnal((SSingnal*)s);
				          break;
				    }

                case TPID_Instrument: {
                  s =new SInstrument();
					        packageFactory.toStructs(&p,(SInstrument*) s);
                  
				          sig_SInstrument((SInstrument*)s);
				          break;
				    }

                case TPID_RiskControler: {
                  s =new SRiskControler();
					        packageFactory.toStructs(&p,(SRiskControler*) s);
                  
				          sig_SRiskControler((SRiskControler*)s);
				          break;
				    }

                case TPID_MoneyChange: {
                  s =new SMoneyChange();
					        packageFactory.toStructs(&p,(SMoneyChange*) s);
                  
				          sig_SMoneyChange((SMoneyChange*)s);
				          break;
				    }

                case TPID_NewTradingDay: {
                  s =new SNewTradingDay();
					        packageFactory.toStructs(&p,(SNewTradingDay*) s);
                  
				          sig_SNewTradingDay((SNewTradingDay*)s);
				          break;
				    }

                case TPID_OrderRsp: {
                  s =new SOrderRsp();
					        packageFactory.toStructs(&p,(SOrderRsp*) s);
                  OrderRspW->addRecord((SOrderRsp*) s);
				          sig_SOrderRsp((SOrderRsp*)s);
				          break;
				    }

                case TPID_MarginRate: {
                  s =new SMarginRate();
					        packageFactory.toStructs(&p,(SMarginRate*) s);
                  
				          sig_SMarginRate((SMarginRate*)s);
				          break;
				    }

                case TPID_FeeRate: {
                  s =new SFeeRate();
					        packageFactory.toStructs(&p,(SFeeRate*) s);
                  
				          sig_SFeeRate((SFeeRate*)s);
				          break;
				    }

                case TPID_LogConfig: {
                  s =new SLogConfig();
					        packageFactory.toStructs(&p,(SLogConfig*) s);
                  
				          sig_SLogConfig((SLogConfig*)s);
				          break;
				    }

				default:{}
			    }               
                free(s);
		    }
            
            if (MDqueue->getSize() != 0) {
                MDqueue->pop(&p);
                s =new SMarketData();
                packageFactory.toStructs(&p,(SMarketData*) s);
                sig_SMarketData((SMarketData*)s); 
                delete s;
            }
	    }
		boost::this_thread::sleep(td);
	};
}
#endif //CDATAROUTE_CPP_
		