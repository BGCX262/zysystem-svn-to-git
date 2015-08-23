
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTradeWriter.h
///@brief ���� �ɽ� �ļ���¼��
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:28.736Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./Structs.h"
#include "../util/DataFile.h"

#ifndef CTRADEWRITER_H_
#define CTRADEWRITER_H_

namespace ZYSystem {
    class CTradeWriter:public CDataFile{
        private:
            //�洢�ļ�
            boost::iostreams::stream<boost::iostreams::file_sink> out;
              
            //�����ļ�title
            void makeTitle();
            
            TDate nowTradingDay;
            TPath dataPath;
			TFile fileName;
			std::ios::openmode mode;

        public:
            CTradeWriter(const TPath dataPath_In,TFile fileName_in ="Trade");
            ~CTradeWriter(void);

            //������¼
            //@param in ��Ҫ�洢�Ľṹ��
            void addRecord(STrade* in);
            
            //�����ļ�����ģʽ
            //@param mode �ļ�����ģʽ
            void setMode(std::ios::openmode mode_in = std::ios::ate);
    };
}
#endif //CTRADEWRITER_H_
      