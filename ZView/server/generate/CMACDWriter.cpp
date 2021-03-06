
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMACDWriter.cpp
///@brief 实现 MACD指标 文件记录器
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:30.576Z
/////////////////////////////////////////////////////////////////////////
#include "CMACDWriter.h"

using namespace ZYSystem;

#ifndef CMACDWRITER_CPP_
#define CMACDWRITER_CPP_

CMACDWriter::CMACDWriter(const TPath dataPath_In,TFile fileName_in){
		if(!boost::filesystem::exists(dataPath_In)) {
				boost::filesystem::create_directories(dataPath_In);
		}

        std::strcpy(this->nowTradingDay,"");
		std::strcpy(this->dataPath,dataPath_In);
		std::strcpy(this->fileName,fileName_in);
		mode = std::ios::out;
}

CMACDWriter::~CMACDWriter(void){
		out.flush();
		out.close();
}

void CMACDWriter::addRecord(SMACD* in){
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
				
        out << in->UpdateTime << ",";
				
        out << in->UpdateMillisec << ",";
				
        out << in->Idx_diff << ",";
				
        out << in->Idx_dea << ",";
				
        out << in->Idx_bar << ",";
				
		out.flush();
}

void CMACDWriter::makeTitle(){
	
		out << "TradingDay,";
				
		out << "InstrumentID,";
				
		out << "ExchangeID,";
				
		out << "UpdateTime,";
				
		out << "UpdateMillisec,";
				
		out << "Idx_diff,";
				
		out << "Idx_dea,";
				
		out << "Idx_bar,";
				
		out.flush();
}

void CMACDWriter::setMode(std::ios::openmode mode_in){
    mode = mode_in;
}

#endif //CMACDWRITER_CPP_
			