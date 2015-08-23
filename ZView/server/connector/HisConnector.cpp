/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file HisConnector.cpp
///@brief ʵ����ʷ��������������
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "HisConnector.h"

#ifndef CHISCONNECTOR_CPP_
#define CHISCONNECTOR_CPP_

using namespace ZYSystem;

CHisConnector::CHisConnector(SMarketDataProvider* in):CConnector(in){
	
    TID reason;

    reason = getMd_url(in->Md_url);
    CHECK_SUCCESS_NoRet(reason);

    reason = getTd_url(in->Td_url,in->InvestorID);
    CHECK_SUCCESS_NoRet(reason);

	CTimeTranslator::getInstance()->getToday(tradingDay); 
}

TID CHisConnector::getMd_url(TURL md_url){
    //��λ���ŷָ���
	int offset = 0;
	while(1) {

		//�����߽���˳�
		if (offset == sizeof TURL) {
			return -1;
		}

		if (md_url[offset] == ',') {
			break;
		}

		offset++;
	}

	//��ʷ����
	std::memcpy(historyDate,md_url+offset+1,sizeof TDate);
	
    //���ݻ���·��
	std::memcpy(basePath,md_url,offset);
	basePath[offset] = NULL;

    return SUCCESS;
}

TID CHisConnector::getTd_url(TURL Td_url,TInvestorID investorID){
    
    std::string temp = std::string(Td_url);
    
    std::vector<std::string> splitVec;
    splitVec.clear();
    
    if (temp.empty()) {
        return -1;
    }
    
    if (temp.find(',') == temp.npos) {
        return -1;
    }
    
    boost::algorithm::split(splitVec,temp,boost::is_any_of(","),boost::algorithm::token_compress_off);

    if (splitVec.size() != 0) {
       
        SMoneyChange moneyChange;
        strcpy(moneyChange.InvestorID,investorID);
        moneyChange.Change = boost::lexical_cast<double>(splitVec[0].c_str());
        moneyChange.FundDirection = FD_In;

        sendTP(&moneyChange);

        SInstrument instrument;
        strcpy(instrument.InstrumentID,splitVec[1].c_str());
        instrument.Multiple = boost::lexical_cast<int>(splitVec[2].c_str());
        
        sendTP(&instrument);
			 
		return SUCCESS;
	} else {
		return -1;
	} 
}

CHisConnector::~CHisConnector(void){

}

//���ӵ�Զ�˷�����
void CHisConnector::connect(void){
	
	//��ʷ����ָ�
	TPath nowDatapath;
	SMarketData temp = SMarketData();

	//����ȵ�ǰ�������磬���п��ܴ�����ʷ����
	while (std::strcmp(historyDate,this ->tradingDay) <= 0) {		
		getDayDataPath(nowDatapath,historyDate);
		CMarketDataReader* reader = new CMarketDataReader(nowDatapath);
	
		ZYSYSTEM_LOG1(CONNECTOR_HIS_TradingDayIs,historyDate);
		SNewTradingDay newTradingDay;
		std::strcpy(newTradingDay.TradingDay,historyDate);

		int i = reader->readRecord(&temp);
		while (i != -1) {
			//��Ҫ���˿���ǰ���������飬nnd			
			if (i == 0 && (std::strcmp(temp.UpdateTime,MAKERT_OPEN_TIME)>0)) {
				//���ն��ĵ����飬����
				if (std::strcmp(temp.InstrumentID,instrumentSub) == 0) {
					//����
					sendTP(&temp);
				}
			}
			i = reader->readRecord(&temp);
			std::strcpy(temp.TradingDay,historyDate);
		}	
		delete reader;
		//��ʷ�����ռ�1
		boost::gregorian::date historyDateG(boost::gregorian::from_undelimited_string(historyDate));
		historyDateG = historyDateG + boost::gregorian::days(1);
		strcpy(historyDate,(boost::gregorian::to_iso_string(historyDateG)).c_str());
	}	
}

//�Ͽ�����
void CHisConnector::disconnect(void){
}

//����ָ���������
TID CHisConnector::subscribeMarketData(SSubInstrument* instruments){
	std::memcpy(this->instrumentSub,instruments->InstrumentID,sizeof TInstrumentID);
	return SUCCESS;
}

void CHisConnector::getDayDataPath(TPath nowDatapath,TDate historyDate){
	std::sprintf(nowDatapath,"%s/%s/",basePath,historyDate);
}


TID CHisConnector::newOrder(SOrderReq* newOrder) {
	orderQueue.push(newOrder);
	return SUCCESS;
}

TID CHisConnector::newMarketData(SMarketData* newMarketData) {
	return SUCCESS;
}

#endif // CHISCONNECTOR_CPP_