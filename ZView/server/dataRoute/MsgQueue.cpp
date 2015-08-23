/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file MsgQueue.cpp
///@brief 消息队列的实现，专门为数据路由定制的有锁阻塞式队列实现
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "MsgQueue.h"

#ifndef CMSGQUEQUE_CPP_
#define CMSGQUEQUE_CPP_

using namespace ZYSystem;

CMsgQueue::CMsgQueue(TVolume max_size_in)
{
	max_size =(std::size_t) max_size_in;
	close_flag = false;
	if (max_size < 1)
	{
		ZYSYSTEM_LOG0(DATAROUTE_MsgQueMaxSizeLessOne);
	}
}

CMsgQueue::~CMsgQueue()
{
	close();       
}

void CMsgQueue::push(CTPackage* msg)
{   
	if (msg == NULL) {
		ZYSYSTEM_LOG0(DATAROUTE_MsgEmpty);
		return;
	}
	boost::mutex::scoped_lock lock(mtx);
	while (msgs.size() >= max_size && !close_flag) {           
		full_cond.wait(lock);
	}

	if (close_flag) {
		ZYSYSTEM_LOG0(DATAROUTE_MsgQueClosed);
	}
	msgs.push(*msg);
    
	if(msgs.size() == 1) {
		empty_cond.notify_all();   
	} 
}

void CMsgQueue::pop(CTPackage* msg)
{
	if (msg == NULL) {
		ZYSYSTEM_LOG0(DATAROUTE_MsgEmpty);
		return;
	}
	
	boost::mutex::scoped_lock lock(mtx);
	while (msgs.empty() && !close_flag)
	{           
		empty_cond.wait(lock);
	}
	if (close_flag)
	{
		ZYSYSTEM_LOG0(DATAROUTE_MsgQueClosed);
	}
	*msg = msgs.front();
	msgs.pop();

	if(msgs.size() == max_size - 1)
	{
		full_cond.notify_all();   
	}
}

void CMsgQueue::close()
{
	close_flag = true;
	{
		boost::mutex::scoped_lock lock(mtx);
		full_cond.notify_all();   
		empty_cond.notify_all();
	}       
}

TVolume CMsgQueue::getMaxSize()
{
	return max_size;
}

TVolume CMsgQueue::getSize()
{
	boost::mutex::scoped_lock lock(mtx);
	return msgs.size();
}

#endif //CMSGQUEQUE_CPP_