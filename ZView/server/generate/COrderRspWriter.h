
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file COrderRspWriter.h
///@brief ���� ������Ӧ �ļ���¼��
///@author xsltģ�ʹ���ת������
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
            //�洢�ļ�
            boost::iostreams::stream<boost::iostreams::file_sink> out;
              
            //�����ļ�title
            void makeTitle();
            
            TDate nowTradingDay;
            TPath dataPath;
			TFile fileName;
			std::ios::openmode mode;

        public:
            COrderRspWriter(const TPath dataPath_In,TFile fileName_in ="OrderRsp");
            ~COrderRspWriter(void);

            //������¼
            //@param in ��Ҫ�洢�Ľṹ��
            void addRecord(SOrderRsp* in);
            
            //�����ļ�����ģʽ
            //@param mode �ļ�����ģʽ
            void setMode(std::ios::openmode mode_in = std::ios::ate);
    };
}
#endif //CORDERRSPWRITER_H_
      