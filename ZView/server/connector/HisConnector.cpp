/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file HisConnector.cpp
///@brief 实现历史数据重演连接器
///@author 张弛
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
    //定位逗号分隔符
	int offset = 0;
	while(1) {

		//超过边界就退出
		if (offset == sizeof TURL) {
			return -1;
		}

		if (md_url[offset] == ',') {
			break;
		}

		offset++;
	}

	//历史日期
	std::memcpy(historyDate,md_url+offset+1,sizeof TDate);
	
    //数据基础路径
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

//连接到远端服务器
void CHisConnector::connect(void){
	
	//历史行情恢复
	TPath nowDatapath;
	SMarketData temp = SMarketData();

	//如果比当前交易日早，则还有可能存在历史数据
	while (std::strcmp(historyDate,this ->tradingDay) <= 0) {		
		getDayDataPath(nowDatapath,historyDate);
		CMarketDataReader* reader = new CMarketDataReader(nowDatapath);
	
		ZYSYSTEM_LOG1(CONNECTOR_HIS_TradingDayIs,historyDate);
		SNewTradingDay newTradingDay;
		std::strcpy(newTradingDay.TradingDay,historyDate);

		int i = reader->readRecord(&temp);
		while (i != -1) {
			//还要过滤开盘前的无用行情，nnd			
			if (i == 0 && (std::strcmp(temp.UpdateTime,MAKERT_OPEN_TIME)>0)) {
				//按照订阅的行情，过滤
				if (std::strcmp(temp.InstrumentID,instrumentSub) == 0) {
					//发出
					sendTP(&temp);
				}
			}
			i = reader->readRecord(&temp);
			std::strcpy(temp.TradingDay,historyDate);
		}	
		delete reader;
		//历史交易日加1
		boost::gregorian::date historyDateG(boost::gregorian::from_undelimited_string(historyDate));
		historyDateG = historyDateG + boost::gregorian::days(1);
		strcpy(historyDate,(boost::gregorian::to_iso_string(historyDateG)).c_str());
	}	
}

//断开连接
void CHisConnector::disconnect(void){
}

//订阅指定标地行情
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