/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTimeTranslator.cpp
///@brief ʱ���������ת����ʵ��,�������е�ʱ���ʽ��������ת��,����ģʽ
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "CTimeTranslator.h"

#ifndef CTIMETRANSLATOR_CPP_
#define CTIMETRANSLATOR_CPP_

using namespace ZYSystem;

CTimeTranslator* CTimeTranslator::instance = NULL;

CTimeTranslator::CTimeTranslator(void)
{
	date_input_formatter = new boost::gregorian::date_input_facet("%Y%m%d");
	time_input_formatter = new boost::posix_time::time_input_facet("%Y%m%d %H:%M:%S");
	time_input_formatter->time_duration_format("%H:%M:%S");
}


CTimeTranslator::~CTimeTranslator(void)
{
}

CTimeTranslator* CTimeTranslator::getInstance(){
	if (instance == NULL) {
		instance =new CTimeTranslator();
	}

	return instance;
}

boost::posix_time::ptime CTimeTranslator::mdkToPtime(SMarketData* in){
	boost::gregorian::date tradingDay;

	//������Ľ������п����ǿյ�
	if (in->TradingDay != NULL && std::strlen(in->TradingDay) != 0) {
		tradingDay = boost::gregorian::date(
			boost::gregorian::from_undelimited_string(std::string(in->TradingDay))
		);
	} else {
		tradingDay = boost::gregorian::date(boost::gregorian::day_clock::local_day());
	}
   
	//ʱ��ת����������ĸ���ʱ��ת��Ϊtime_duration
	boost::posix_time::time_duration timeDuration(boost::posix_time::duration_from_string(in->UpdateTime));
	timeDuration = timeDuration + boost::posix_time::milliseconds(in->UpdateMillisec);

	return boost::posix_time::ptime(tradingDay,timeDuration);
}

void CTimeTranslator::getToday(TDate today){
	std::memcpy(today,
		std::string(boost::gregorian::to_iso_string(boost::gregorian::day_clock::local_day()).substr(0,8)).c_str(),
		sizeof TDate		
		);
}

#endif //CTIMEFPORMATTER_CPP_
