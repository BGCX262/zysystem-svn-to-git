
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMarketDataReader.cpp
///@brief 实现 系统接收到的行情数据 文件读取器
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:34.289Z
/////////////////////////////////////////////////////////////////////////
#include "CMarketDataReader.h"

using namespace ZYSystem;

#ifndef CMARKETDATAREADER_CPP_
#define CMARKETDATAREADER_CPP_

CMarketDataReader::CMarketDataReader(const TPath dataPath_In,TFile fileName_in){
	TFile fileName;
	sprintf(fileName,"%s%s.csv",dataPath_In,fileName_in);
	boost::iostreams::file_source thisfile(fileName);
	in.open(thisfile,std::ios::beg);
}

CMarketDataReader::~CMarketDataReader(void){
    in.close();
}

TID CMarketDataReader::readRecord(SMarketData* out){
    std::string temp;
    std::getline(in,temp);
    splitVec.clear();
    
    if (temp.empty()) {
        return -1;
    }
    
    if (temp.find(',') == temp.npos) {
        return -1;
    }
    
    boost::algorithm::split(splitVec,temp,boost::is_any_of(","),boost::algorithm::token_compress_off);

    if (splitVec.size() != 0) {
        
        if("TradingDay" == splitVec[0]) {
            return -2;
        }
                     
		strcpy(out->TradingDay,splitVec[0].c_str());
					 
		strcpy(out->InstrumentID,splitVec[1].c_str());
					 
		strcpy(out->ExchangeID,splitVec[2].c_str());
					 
        out->LastPrice = boost::lexical_cast<double>(splitVec[3].c_str());
					 
        out->PreSettlementPrice = boost::lexical_cast<double>(splitVec[4].c_str());
					 
        out->PreClosePrice = boost::lexical_cast<double>(splitVec[5].c_str());
					 
        out->PreOpenInterest = boost::lexical_cast<double>(splitVec[6].c_str());
					 
        out->OpenPrice = boost::lexical_cast<double>(splitVec[7].c_str());
					 
        out->HighestPrice = boost::lexical_cast<double>(splitVec[8].c_str());
					 
        out->LowestPrice = boost::lexical_cast<double>(splitVec[9].c_str());
					 
        out->Volume = boost::lexical_cast<int>(splitVec[10].c_str());
					 
        out->Turnover = boost::lexical_cast<double>(splitVec[11].c_str());
					 
        out->OpenInterest = boost::lexical_cast<double>(splitVec[12].c_str());
					 
        out->ClosePrice = boost::lexical_cast<double>(splitVec[13].c_str());
					 
        out->SettlementPrice = boost::lexical_cast<double>(splitVec[14].c_str());
					 
        out->UpperLimitPrice = boost::lexical_cast<double>(splitVec[15].c_str());
					 
        out->LowerLimitPrice = boost::lexical_cast<double>(splitVec[16].c_str());
					 
        out->PreDelta = boost::lexical_cast<double>(splitVec[17].c_str());
					 
        out->CurrDelta = boost::lexical_cast<double>(splitVec[18].c_str());
					 
		strcpy(out->UpdateTime,splitVec[19].c_str());
					 
        out->UpdateMillisec = boost::lexical_cast<int>(splitVec[20].c_str());
					 
        out->BidPrice1 = boost::lexical_cast<double>(splitVec[21].c_str());
					 
        out->BidVolume1 = boost::lexical_cast<int>(splitVec[22].c_str());
					 
        out->AskPrice1 = boost::lexical_cast<double>(splitVec[23].c_str());
					 
        out->AskVolume1 = boost::lexical_cast<int>(splitVec[24].c_str());
					 
        out->AveragePrice = boost::lexical_cast<double>(splitVec[25].c_str());
					 
		return 0;
	} else {
		return -1;
	}    
}

#endif //CMARKETDATAREADER_CPP_
			