/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.cpp
///@brief 主程序容器,用于执行Zy system的所有功能. 
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "ZYSystemMain.h"

#ifndef ZYSYSTEMMAIN_CPP_
#define ZYSYSTEMMAIN_CPP_

using namespace ZYSystem;

ZYSystemMain::ZYSystemMain(CConfigXml* configXML_in)
{	
	//创建配置文件实例
	configXML = configXML_in;

	//设置数据文件路径
	configXML_in->getDataPath(CDataFile::dataPath);

	//订阅合约
	SSubInstrument subInstrument;
	configXML->getInstruments(subInstrument.InstrumentID);
	CTPackage tpackage = CTPackage();
	CTPackageFactory* factory =new CTPackageFactory();
	factory->toCTP(&subInstrument,&tpackage);
	CDataRoute::getInstance()->send(&tpackage);

	//初始化投资者
	initInvestor();

	//初始化交易核心;
	initTCore();
	
	//初始化模型
	initModel();

	//初始化连接器
	initConnector();

	CDataRoute::getInstance()->startup();
}


ZYSystemMain::~ZYSystemMain(void)
{	
	//关闭对配置文件的使用;
	delete configXML;
	
	//清除所有投资者
	delete investorMap;
	
	// TODO 关闭行情连接

	// TODO 关闭到期货公司交易系统的连接
	// TODO 关闭所有打开的文件

	//删除日志连接
}

void ZYSystemMain::initConnector(){
	
	//获得服务器的数量
	if (configXML->countConnConfig() == 0) {
		exit(1);//如果没有配置行情服务器则退出程序
	}
	
	//加载行情服务器
	TConnectionID server_id;
	configXML->getServerId(server_id);
		
	SMarketDataProvider* config = new SMarketDataProvider;
	configXML->getConnConfig(server_id,config);

	//先为config查找对应的investor
	SInvestor* investor = NULL;
	investor = getInvestorByInvestorId(config->InvestorID,investor);

	//1:综合交易平台	
	if (config->ConnectionType == MDT_Sfit) {
		
		CASPConnector* aspMDR = new CASPConnector(config);
		aspMDR->newInvestor(investor);

		boost::function<TID (SOrderReq*)> fa = boost::bind(&CASPConnector::newOrder,aspMDR,_1);
		CDataRoute::getInstance()->subscribe(fa);

		CDataRoute::getInstance()->setConnector(boost::bind(&CASPConnector::connect,aspMDR));

	} else if (config->ConnectionType == MDT_His) {
		
		CHisConnector* hisMDR = new CHisConnector(config);

		boost::function<TID (SOrderReq*)> fa = boost::bind(&CHisConnector::newOrder,hisMDR,_1);
		CDataRoute::getInstance()->subscribe(fa);
		
		boost::function<TID (SSubInstrument*)> fb = boost::bind(&CHisConnector::subscribeMarketData,hisMDR,_1);
		CDataRoute::getInstance()->subscribe(fb);

		CDataRoute::getInstance()->setConnector(boost::bind(&CHisConnector::connect,hisMDR));

	} else if (config->ConnectionType == MDT_Sim) {
		
		CSimConnector* simMDR = new CSimConnector(config);
		simMDR->newInvestor(investor);

		boost::function<TID (SOrderReq*)> fa = boost::bind(&CSimConnector::newOrder,simMDR,_1);
		CDataRoute::getInstance()->subscribe(fa);

		boost::function<TID (SSubInstrument*)> fb = boost::bind(&CSimConnector::subscribeMarketData,simMDR,_1);
		CDataRoute::getInstance()->subscribe(fb);

		CDataRoute::getInstance()->setConnector(boost::bind(&CSimConnector::connect,simMDR));

	} else if (config->ConnectionType == MDT_OnlyMD) {
		
		CMDOnlyConnector* onlyMDR = new CMDOnlyConnector(config);
		onlyMDR->newInvestor(investor);

		CDataRoute::getInstance()->setConnector(boost::bind(&CMDOnlyConnector::connect,onlyMDR));
	}
}

SInvestor* ZYSystemMain::getInvestorByInvestorId(char* in,SInvestor* ret){
	if (in == NULL) {
		return NULL;
	}
	int iInvestor = configXML->countInvestor();
	//取出符合输入TInvestorID的SInvestor
	for (int i=0;i <iInvestor;i++) {
		if (strncmp(in,investorMap->InvestorID,6) == 0) {
			ret = investorMap;
			return ret;
		}
		investorMap++;
	}

	return NULL;
}

//初始化投资者
void ZYSystemMain::initInvestor(){
	//获得投资者的数量
	int iInvestor = configXML->countInvestor();	

	if (iInvestor == 0) {
		//没有投资者则退出程序
		exit(1);
	} else {
		investorMap =new SInvestor[iInvestor];

		//加载投资者
		SInvestor investor;
		for(int i=1;i<=iInvestor;i++) {
			investor = SInvestor();
			configXML->getInvestor(i,&investor);
			investorMap[i-1] = investor;
		}
	}
	
	//完成投资者加载
}

void ZYSystemMain::initModel(){
	//获得模型的数量
	int iModel = configXML->countModel();
	
	if (iModel == 0) {
		exit(1);//如果没有配置行情服务器则退出程序
	} else {
		//加载行情服务器
		modelMap =new SModelConfigA[iModel];
		
		SModelConfigA modelConfigA;
		for(int i=1;i <= iModel;i++) {
			modelConfigA = SModelConfigA();
			configXML->getModel(i,&modelConfigA);
			modelMap[i-1] = modelConfigA;
			if (this->dataRoute != NULL) {
				modelA = new CCalModelA(modelConfigA);
			}			
		}
	}
	//完成行情服务器加载
}

void ZYSystemMain::initTCore(){
	tCore =new TCore();
	tCore->createInvestor(&(investorMap[0]));

	boost::function<TID (SMoneyChange*)> fa = boost::bind(&TCore::changeFund,tCore,_1);
	CDataRoute::getInstance()->subscribe(fa);

	boost::function<TID (SMarketData*)> fb = boost::bind(&TCore::newMarketData,tCore,_1);
	CDataRoute::getInstance()->subscribe(fb);

	boost::function<TID (STrade*)> fc = boost::bind(&TCore::newTrade,tCore,_1);
	CDataRoute::getInstance()->subscribe(fc);

	boost::function<TID (SOrderRsp*)> fd = boost::bind(&TCore::newOrderRespone,tCore,_1);
	CDataRoute::getInstance()->subscribe(fd);

	boost::function<TID (SFeeRate*)> fe = boost::bind(&TCore::newFeeRate,tCore,_1);
	CDataRoute::getInstance()->subscribe(fe);

	boost::function<TID (SMarginRate*)> ff = boost::bind(&TCore::newMarginRate,tCore,_1);
	CDataRoute::getInstance()->subscribe(ff);

	boost::function<TID (SInvestor*)> fg = boost::bind(&TCore::createInvestor,tCore,_1);
	CDataRoute::getInstance()->subscribe(fg);
}

#endif // ZYSYSTEMMAIN_CPP_