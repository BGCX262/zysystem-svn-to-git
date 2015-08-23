
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMarketDataReader.h
///@brief ���� ϵͳ���յ����������� �ļ���ȡ��
///@author xsltģ�ʹ���ת������
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
            //�洢�ļ�
            boost::iostreams::stream<boost::iostreams::file_source> in;
            std::vector<std::string> splitVec;

        public:
            //�����dataPath_In������·��
            CMarketDataReader(const TPath dataPath_In,TFile fileName_in ="MarketData");
            ~CMarketDataReader(void);

            //������¼
            //@param in ��Ҫ�洢�Ľṹ��
            TID readRecord(SMarketData* out);
    };
}
#endif //CMARKETDATAREADER_H_
            