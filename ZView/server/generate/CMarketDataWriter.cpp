
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMarketDataWriter.cpp
///@brief 实现 系统接收到的行情数据 文件记录器
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:30.576Z
/////////////////////////////////////////////////////////////////////////
#include "CMarketDataWriter.h"

using namespace ZYSystem;

#ifndef CMARKETDATAWRITER_CPP_
#define CMARKETDATAWRITER_CPP_

CMarketDataWriter::CMarketDataWriter(const TPath dataPath_In,TFile fileName_in){
		if(!boost::filesystem::exists(dataPath_In)) {
				boost::filesystem::create_directories(dataPath_In);
		}

        std::strcpy(this->nowTradingDay,"");
		std::strcpy(this->dataPath,dataPath_In);
		std::strcpy(this->fileName,fileName_in);
		mode = std::ios::out;
}

CMarketDataWriter::~CMarketDataWriter(void){
		out.flush();
		out.close();
}

void CMarketDataWriter::addRecord(SMarketData* in){
		if (std::strlen(nowTradingDay) == 0 || std::strcmp(nowTradingDay,in->TradingDay) != 0 ) {		
			if (out.is_open()) {
				out.close();
			}			
			
			std::strcpy(nowTradingDay,in->TradingDay);

			TFile thisFileName;
			sprintf(thisFileName,"%s%s/%s.csv",dataPath,nowTradingDay,fileName);
			boost::iostreams::file_sink thisfile(thisFileName,mode);
			out.open(thisfile);

            if (boost::filesystem::exists(thisFileName) && 
				(boost::filesystem::file_size(thisFileName) > 10)) {
					out << std::endl << "new data after restart" << boost::posix_time::second_clock::local_time() << std::endl;
			} else {
				makeTitle();
			}
		}
        
        out << std::endl;
		
        out << in->TradingDay << ",";
				
        out << in->InstrumentID << ",";
				
        out << in->ExchangeID << ",";
				
        out << in->LastPrice << ",";
				
        out << in->PreSettlementPrice << ",";
				
        out << in->PreClosePrice << ",";
				
        out << in->PreOpenInterest << ",";
				
        out << in->OpenPrice << ",";
				
        out << in->HighestPrice << ",";
				
        out << in->LowestPrice << ",";
				
        out << in->Volume << ",";
				
        out << in->Turnover << ",";
				
        out << in->OpenInterest << ",";
				
        out << in->ClosePrice << ",";
				
        out << in->SettlementPrice << ",";
				
        out << in->UpperLimitPrice << ",";
				
        out << in->LowerLimitPrice << ",";
				
        out << in->PreDelta << ",";
				
        out << in->CurrDelta << ",";
				
        out << in->UpdateTime << ",";
				
        out << in->UpdateMillisec << ",";
				
        out << in->BidPrice1 << ",";
				
        out << in->BidVolume1 << ",";
				
        out << in->AskPrice1 << ",";
				
        out << in->AskVolume1 << ",";
				
        out << in->AveragePrice << ",";
				
		out.flush();
}

void CMarketDataWriter::makeTitle(){
	
		out << "TradingDay,";
				
		out << "InstrumentID,";
				
		out << "ExchangeID,";
				
		out << "LastPrice,";
				
		out << "PreSettlementPrice,";
				
		out << "PreClosePrice,";
				
		out << "PreOpenInterest,";
				
		out << "OpenPrice,";
				
		out << "HighestPrice,";
				
		out << "LowestPrice,";
				
		out << "Volume,";
				
		out << "Turnover,";
				
		out << "OpenInterest,";
				
		out << "ClosePrice,";
				
		out << "SettlementPrice,";
				
		out << "UpperLimitPrice,";
				
		out << "LowerLimitPrice,";
				
		out << "PreDelta,";
				
		out << "CurrDelta,";
				
		out << "UpdateTime,";
				
		out << "UpdateMillisec,";
				
		out << "BidPrice1,";
				
		out << "BidVolume1,";
				
		out << "AskPrice1,";
				
		out << "AskVolume1,";
				
		out << "AveragePrice,";
				
		out.flush();
}

void CMarketDataWriter::setMode(std::ios::openmode mode_in){
    mode = mode_in;
}

#endif //CMARKETDATAWRITER_CPP_
			