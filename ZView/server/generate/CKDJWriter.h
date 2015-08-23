
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CKDJWriter.h
///@brief 声明 KDJ指标 文件记录器
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:28.736Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./Structs.h"
#include "../util/DataFile.h"

#ifndef CKDJWRITER_H_
#define CKDJWRITER_H_

namespace ZYSystem {
    class CKDJWriter:public CDataFile{
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
            CKDJWriter(const TPath dataPath_In,TFile fileName_in ="KDJ");
            ~CKDJWriter(void);

            //新增记录
            //@param in 需要存储的结构体
            void addRecord(SKDJ* in);
            
            //设置文件操作模式
            //@param mode 文件操作模式
            void setMode(std::ios::openmode mode_in = std::ios::ate);
    };
}
#endif //CKDJWRITER_H_
      