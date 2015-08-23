#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMDBufferQueue.h
///@brief ������ּ���ָ��������Ƶ����黺����У�֧�ֶ���Ԫ�صĲ��롢ɾ�������ʣ������� 
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../generate/Gen.h"

#ifndef CMDBUFFERQUEUE_H_
#define CMDBUFFERQUEUE_H_

namespace ZYSystem {

	template<typename TC> class CMDBufferQueue{
	private:

		///@brief ���е���󳤶�
		int maxSize;
		
		///@brief ���г���
        int size;
		
		///@brief ���е�ͷ
		int front;

		///@brief ���е�β
		int back;

		///@brief ����
		TC* queue;
	public:

		///@brief ���Ŀǰ������еĴ�С
		///@return	����Ŀǰ�ĳ���
		///@remark
		int getSize(){
			return this->size;
		};

		///@brief �Ӷ������ͷ�
		///@remark
		void pop(TC* temp){
			front++;
			size--;
			if (size < 0) {
				front--;
				size++;
			}
	
			if (front == maxSize) {
				front = 0;
			}

			std::memcpy(temp,&queue[front],sizeof TC);
		};

		///@brief ��һ������������
		///@param in ����Ķ���
		///@remark
		void push(TC* in){
			back++;
			size++;
			if (size > maxSize) {
				back--;
				size--;
				return;
			}

			if (back == maxSize) {
				back = 0;
			}

			std::memcpy(&queue[back],in,sizeof TC);	
		};

		///@brief ������������еĿ���\���\���\����
		///@param in ����õ�����ֵ�������������
		///@remark
		void assembleMD(SMarketData* in){
			in->LastPrice = 0;
			in->LowestPrice = LOWESTPRICE_INIT;
			in->HighestPrice = 0;
			in->OpenPrice = 0;

			int index = 0;		
			for(int i=0;i<size;i++) {

				index = i + front;
				if (index >= maxSize) {
					index = index - size;
				}

				in->LastPrice = queue[index].LastPrice;
				in->ClosePrice = queue[index].ClosePrice;

				if (in->OpenPrice == 0) {
					in->OpenPrice = queue[index].OpenPrice;
				}
		
				if (in->HighestPrice < queue[index].HighestPrice) {
					in->HighestPrice = queue[index].HighestPrice;
				}

				if (in->LowestPrice > queue[index].LowestPrice) {
					in->LowestPrice = queue[index].LowestPrice;
				}
			}
		};

		///@brief ���
		///@param index ��Ҫ�Ƚϵı���
		///@param in ����
		///@param trade �ɽ�
		///@remark
		TID simTrade(int index,SMarketData* in,STrade* trade){
			if (size < index) {
				return -1;
			}

			//���
			if (queue[index].Direction == D_Buy) {
				if (queue[index].Price >= in->LastPrice) {
					
					std::strcpy(trade->TradingDay,in->TradingDay);
					std::strcpy(trade->InvestorID,queue[index].InvestorID);
					std::strcpy(trade->InstrumentID,in->InstrumentID);
					trade->OffsetFlag = queue[index].OffsetFlag;
					trade->Direction = queue[index].Direction;
					trade->DoneVolume = queue[index].Volume;
					trade->DonePrice = in->LastPrice;
					std::strcpy(trade->TradeTime,in->UpdateTime);
					trade->LocalOrderID = queue[index].LocalOrderID;
					trade->Multiple = queue[index].Multiple;

					TC* in = new TC();
					pop(in);
					delete in;

					return SUCCESS;			
				}
			} else {
				if (queue[index].Price <= in->LastPrice) {

					std::strcpy(trade->TradingDay,in->TradingDay);
					std::strcpy(trade->InvestorID,queue[index].InvestorID);
					std::strcpy(trade->InstrumentID,in->InstrumentID);
					trade->OffsetFlag = queue[index].OffsetFlag;
					trade->Direction = queue[index].Direction;
					trade->DoneVolume = queue[index].Volume;
					trade->DonePrice = in->LastPrice;
					std::strcpy(trade->TradeTime,in->UpdateTime);
					trade->LocalOrderID = queue[index].LocalOrderID;
					trade->Multiple = queue[index].Multiple;

					TC* in =  new TC();
					pop(in);
					delete in;

					return SUCCESS;			
				}
			}

            return -1;
		};

		///@brief ���黺����� ���캯��
		///@param size_in ����õ�����ֵ�������������
		///@remark
		CMDBufferQueue(int size_in = 5){
			queue = new TC[size_in];
			this->maxSize = size_in;
			this->size = 0;
			this->front = -1;
			this->back = -1;
		};
		///@brief ���黺����� ��������
		~CMDBufferQueue(void){};
	};
}

#endif //CMDBUFFERQUEUE_H_