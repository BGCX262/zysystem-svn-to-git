#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTimeTranslator.h
///@brief 时间转换格式化器声明,负责所有的时间格式化操作、转换,单例模式
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#ifndef CTIMETRANSLATOR_H_
#define CTIMETRANSLATOR_H_

#include "../generate/Gen.h"

namespace ZYSystem {
    
    class CTimeTranslator
    {
        private:
            ///@brief 日期格式化器 YYYYMMDD
            boost::gregorian::date_input_facet* date_input_formatter;

            ///@brief 分时秒格式化器 HH:MM:SS
            boost::posix_time::time_input_facet* time_input_formatter;
            
            ///@brief 行情路由实例
            static CTimeTranslator* instance;
           
            CTimeTranslator(void);

        public:
            ///@brief 获取时间输入输出格式化器实例
			///@return 时间输入输出格式化器
			///@remark 
            static CTimeTranslator* getInstance();

            ///@brief 将行情中的Tradingday和updateTime转换成ptime
			///@param in 行情数据
			///@return 转换后的ptime
			///@remark 
            boost::posix_time::ptime mdkToPtime(SMarketData* in);

			///@brief 获取今天的日期字符串
			///@param today 今天
			void getToday(TDate today);

            ~CTimeTranslator(void);
    };
}
#endif //CTIMETRANSLATOR_H_
