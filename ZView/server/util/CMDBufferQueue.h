#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CMDBufferQueue.h
///@brief 满足各种技术指标计算而设计的行情缓冲队列，支持队列元素的插入、删除、访问，无锁。 
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../generate/Gen.h"

#ifndef CMDBUFFERQUEUE_H_
#define CMDBUFFERQUEUE_H_

namespace ZYSystem {

	template<typename TC> class CMDBufferQueue{
	private:

		///@brief 队列的最大长度
		int maxSize;
		
		///@brief 队列长度
        int size;
		
		///@brief 队列的头
		int front;

		///@brief 队列的尾
		int back;

		///@brief 队列
		TC* queue;
	public:

		///@brief 获得目前行情队列的大小
		///@return	队列目前的长度
		///@remark
		int getSize(){
			return this->size;
		};

		///@brief 从队列中释放
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

		///@brief 将一个对象放入队列
		///@param in 放入的对象
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

		///@brief 计算行情队列中的开盘\最低\最高\收盘
		///@param in 计算好的行情值放在这个对象里
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

		///@brief 撮合
		///@param index 需要比较的报单
		///@param in 行情
		///@param trade 成交
		///@remark
		TID simTrade(int index,SMarketData* in,STrade* trade){
			if (size < index) {
				return -1;
			}

			//撮合
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

		///@brief 行情缓冲队列 构造函数
		///@param size_in 计算好的行情值放在这个对象里
		///@remark
		CMDBufferQueue(int size_in = 5){
			queue = new TC[size_in];
			this->maxSize = size_in;
			this->size = 0;
			this->front = -1;
			this->back = -1;
		};
		///@brief 行情缓冲队列 析构函数
		~CMDBufferQueue(void){};
	};
}

#endif //CMDBUFFERQUEUE_H_