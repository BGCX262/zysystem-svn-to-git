
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMarketDataWriter.h
///@brief 声明 系统接收到的行情数据 文件记录器
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:28.736Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./Structs.h"
#include "../util/DataFile.h"

#ifndef CMARKETDATAWRITER_H_
#define CMARKETDATAWRITER_H_

namespace ZYSystem {
    class CMarketDataWriter:public CDataFile{
        private:
            //存储文件
            boost::iostreams::stream<boost::iostreams::file_sink> out;
              
            //创建文件title
            void makeTitle();
            
            TDate nowTradingDay;
            TPath dataPath;
			TFile fileName;
			std::ios::openmode mode;

        public:
            CMarketDataWriter(const TPath dataPath_In,TFile fileName_in ="MarketData");
            ~CMarketDataWriter(void);

            //新增记录
            //@param in 需要存储的结构体
            void addRecord(SMarketData* in);
            
            //设置文件操作模式
            //@param mode 文件操作模式
            void setMode(std::ios::openmode mode_in = std::ios::ate);
    };
}
#endif //CMARKETDATAWRITER_H_
      