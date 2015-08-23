
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file COrderRspWriter.h
///@brief 声明 报单响应 文件记录器
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:28.736Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./Structs.h"
#include "../util/DataFile.h"

#ifndef CORDERRSPWRITER_H_
#define CORDERRSPWRITER_H_

namespace ZYSystem {
    class COrderRspWriter:public CDataFile{
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
            COrderRspWriter(const TPath dataPath_In,TFile fileName_in ="OrderRsp");
            ~COrderRspWriter(void);

            //新增记录
            //@param in 需要存储的结构体
            void addRecord(SOrderRsp* in);
            
            //设置文件操作模式
            //@param mode 文件操作模式
            void setMode(std::ios::openmode mode_in = std::ios::ate);
    };
}
#endif //CORDERRSPWRITER_H_
      