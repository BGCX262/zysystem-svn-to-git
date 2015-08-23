
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CSingnalWriter.cpp
///@brief 实现 交易信号 文件记录器
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:30.576Z
/////////////////////////////////////////////////////////////////////////
#include "CSingnalWriter.h"

using namespace ZYSystem;

#ifndef CSINGNALWRITER_CPP_
#define CSINGNALWRITER_CPP_

CSingnalWriter::CSingnalWriter(const TPath dataPath_In,TFile fileName_in){
		if(!boost::filesystem::exists(dataPath_In)) {
				boost::filesystem::create_directories(dataPath_In);
		}

        std::strcpy(this->nowTradingDay,"");
		std::strcpy(this->dataPath,dataPath_In);
		std::strcpy(this->fileName,fileName_in);
		mode = std::ios::out;
}

CSingnalWriter::~CSingnalWriter(void){
		out.flush();
		out.close();
}

void CSingnalWriter::addRecord(SSingnal* in){
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
				
        out << in->InvestorID << ",";
				
        out << in->InstrumentID << ",";
				
        out << in->OffsetFlag << ",";
				
        out << in->Direction << ",";
				
        out << in->Volume << ",";
				
        out << in->Price << ",";
				
        out << in->SingnalReason << ",";
				
        out << in->TriggerTime << ",";
				
        out << in->LocalTime << ",";
				
		out.flush();
}

void CSingnalWriter::makeTitle(){
	
		out << "TradingDay,";
				
		out << "InvestorID,";
				
		out << "InstrumentID,";
				
		out << "OffsetFlag,";
				
		out << "Direction,";
				
		out << "Volume,";
				
		out << "Price,";
				
		out << "SingnalReason,";
				
		out << "TriggerTime,";
				
		out << "LocalTime,";
				
		out.flush();
}

void CSingnalWriter::setMode(std::ios::openmode mode_in){
    mode = mode_in;
}

#endif //CSINGNALWRITER_CPP_
			