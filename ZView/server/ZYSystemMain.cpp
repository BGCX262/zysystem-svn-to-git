/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemMain.cpp
///@brief ����������,����ִ��Zy system�����й���. 
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "ZYSystemMain.h"

#ifndef ZYSYSTEMMAIN_CPP_
#define ZYSYSTEMMAIN_CPP_

using namespace ZYSystem;

ZYSystemMain::ZYSystemMain(CConfigXml* configXML_in)
{	
	//���������ļ�ʵ��
	configXML = configXML_in;

	//���������ļ�·��
	configXML_in->getDataPath(CDataFile::dataPath);

	//���ĺ�Լ
	SSubInstrument subInstrument;
	configXML->getInstruments(subInstrument.InstrumentID);
	CTPackage tpackage = CTPackage();
	CTPackageFactory* factory =new CTPackageFactory();
	factory->toCTP(&subInstrument,&tpackage);
	CDataRoute::getInstance()->send(&tpackage);

	//��ʼ��Ͷ����
	initInvestor();

	//��ʼ�����׺���;
	initTCore();
	
	//��ʼ��ģ��
	initModel();

	//��ʼ��������
	initConnector();

	CDataRoute::getInstance()->startup();
}


ZYSystemMain::~ZYSystemMain(void)
{	
	//�رն������ļ���ʹ��;
	delete configXML;
	
	//�������Ͷ����
	delete investorMap;
	
	// TODO �ر���������

	// TODO �رյ��ڻ���˾����ϵͳ������
	// TODO �ر����д򿪵��ļ�

	//ɾ����־����
}

void ZYSystemMain::initConnector(){
	
	//��÷�����������
	if (configXML->countConnConfig() == 0) {
		exit(1);//���û������������������˳�����
	}
	
	//�������������
	TConnectionID server_id;
	configXML->getServerId(server_id);
		
	SMarketDataProvider* config = new SMarketDataProvider;
	configXML->getConnConfig(server_id,config);

	//��Ϊconfig���Ҷ�Ӧ��investor
	SInvestor* investor = NULL;
	investor = getInvestorByInvestorId(config->InvestorID,investor);

	//1:�ۺϽ���ƽ̨	
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
	//ȡ����������TInvestorID��SInvestor
	for (int i=0;i <iInvestor;i++) {
		if (strncmp(in,investorMap->InvestorID,6) == 0) {
			ret = investorMap;
			return ret;
		}
		investorMap++;
	}

	return NULL;
}

//��ʼ��Ͷ����
void ZYSystemMain::initInvestor(){
	//���Ͷ���ߵ�����
	int iInvestor = configXML->countInvestor();	

	if (iInvestor == 0) {
		//û��Ͷ�������˳�����
		exit(1);
	} else {
		investorMap =new SInvestor[iInvestor];

		//����Ͷ����
		SInvestor investor;
		for(int i=1;i<=iInvestor;i++) {
			investor = SInvestor();
			configXML->getInvestor(i,&investor);
			investorMap[i-1] = investor;
		}
	}
	
	//���Ͷ���߼���
}

void ZYSystemMain::initModel(){
	//���ģ�͵�����
	int iModel = configXML->countModel();
	
	if (iModel == 0) {
		exit(1);//���û������������������˳�����
	} else {
		//�������������
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
	//����������������
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