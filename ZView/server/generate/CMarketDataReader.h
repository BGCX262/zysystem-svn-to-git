
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMarketDataReader.h
///@brief 声明 系统接收到的行情数据 文件读取器
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:32.433Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./Structs.h"
#include "../util/DataFile.h"

#ifndef CMARKETDATAREADER_H_
#define CMARKETDATAREADER_H_

namespace ZYSystem {
    class CMarketDataReader:public CDataFile{
        private:
            //存储文件
            boost::iostreams::stream<boost::iostreams::file_source> in;
            std::vector<std::string> splitVec;

        public:
            //这里的dataPath_In是最终路径
            CMarketDataReader(const TPath dataPath_In,TFile fileName_in ="MarketData");
            ~CMarketDataReader(void);

            //新增记录
            //@param in 需要存储的结构体
            TID readRecord(SMarketData* out);
    };
}
#endif //CMARKETDATAREADER_H_
            