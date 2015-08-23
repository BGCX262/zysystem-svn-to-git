#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file MsgQueue.h
///@brief 消息队列，专门为数据路由定制的有锁阻塞式队列
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../generate/gen.h"
#include "TPackage.h"

#ifndef CMSGQUEQUE_H_
#define CMSGQUEQUE_H_

namespace ZYSystem {

	class CMsgQueue
	{
	public:

		///@brief CMsgQueue消息队列构造函数
		///@param max_size_in 队列最大长度
		CMsgQueue(TVolume max_size_in = 500);

		///@brief 获取数据包内容类型
		~CMsgQueue();

		///@brief 送数据包进入队列
		///@param msg 内容指针(不可为空)
		void push(CTPackage* msg);

		///@brief 获取数据包内容类型
		///@param msg 内容指针(不可为空)
		void pop(CTPackage* msg);

		///@brief 关闭队列
		void close();

		///@brief 获取队列的最大长度
		///@return 最大长度
		TVolume getMaxSize();

		///@brief 获取队列的长度
		///@return   队列的当前长度
		TVolume getSize();

	private:
		///@brief 队列操作锁
		boost::mutex mtx;

		///@brief 条件变量：队列满
		boost::condition_variable_any full_cond;

		///@brief 条件变量：队列空
		boost::condition_variable_any empty_cond;

		///@brief 队列
		std::queue<CTPackage> msgs; 

		///@brief 队列的最大长度
		std::size_t max_size;

		///@brief 获取数据包内容类型
		bool close_flag;
	};
}
#endif //CMSGQUEQUE_H_