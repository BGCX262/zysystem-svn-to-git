
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file COrderReqWriter.cpp
///@brief ʵ�� �������� �ļ���¼��
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:30.576Z
/////////////////////////////////////////////////////////////////////////
#include "COrderReqWriter.h"

using namespace ZYSystem;

#ifndef CORDERREQWRITER_CPP_
#define CORDERREQWRITER_CPP_

COrderReqWriter::COrderReqWriter(const TPath dataPath_In,TFile fileName_in){
		if(!boost::filesystem::exists(dataPath_In)) {
				boost::filesystem::create_directories(dataPath_In);
		}

        std::strcpy(this->nowTradingDay,"");
		std::strcpy(this->dataPath,dataPath_In);
		std::strcpy(this->fileName,fileName_in);
		mode = std::ios::out;
}

COrderReqWriter::~COrderReqWriter(void){
		out.flush();
		out.close();
}

void COrderReqWriter::addRecord(SOrderReq* in){
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
		
        out << in->LocalOrderID << ",";
				
        out << in->TradingDay << ",";
				
        out << in->InvestorID << ",";
				
        out << in->InstrumentID << ",";
				
        out << in->OffsetFlag << ",";
				
        out << in->Direction << ",";
				
        out << in->Price << ",";
				
        out << in->OrderStatus << ",";
				
        out << in->OrderSubmitStatus << ",";
				
        out << in->LocalTime << ",";
				
        out << in->OrderTime << ",";
				
        out << in->VolumeTraded << ",";
				
        out << in->VolumeRemain << ",";
				
		out.flush();
}

void COrderReqWriter::makeTitle(){
	
		out << "LocalOrderID,";
				
		out << "TradingDay,";
				
		out << "InvestorID,";
				
		out << "InstrumentID,";
				
		out << "OffsetFlag,";
				
		out << "Direction,";
				
		out << "Price,";
				
		out << "OrderStatus,";
				
		out << "OrderSubmitStatus,";
				
		out << "LocalTime,";
				
		out << "OrderTime,";
				
		out << "VolumeTraded,";
				
		out << "VolumeRemain,";
				
		out.flush();
}

void COrderReqWriter::setMode(std::ios::openmode mode_in){
    mode = mode_in;
}

#endif //CORDERREQWRITER_CPP_
			