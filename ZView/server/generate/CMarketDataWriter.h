
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMarketDataWriter.h
///@brief ���� ϵͳ���յ����������� �ļ���¼��
///@author xsltģ�ʹ���ת������
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
            //�洢�ļ�
            boost::iostreams::stream<boost::iostreams::file_sink> out;
              
            //�����ļ�title
            void makeTitle();
            
            TDate nowTradingDay;
            TPath dataPath;
			TFile fileName;
			std::ios::openmode mode;

        public:
            CMarketDataWriter(const TPath dataPath_In,TFile fileName_in ="MarketData");
            ~CMarketDataWriter(void);

            //������¼
            //@param in ��Ҫ�洢�Ľṹ��
            void addRecord(SMarketData* in);
            
            //�����ļ�����ģʽ
            //@param mode �ļ�����ģʽ
            void setMode(std::ios::openmode mode_in = std::ios::ate);
    };
}
#endif //CMARKETDATAWRITER_H_
      