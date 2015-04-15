/*************************************************************************
	> File Name: thread.h
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sun 29 Mar 2015 09:46:00 PM CST
 ************************************************************************/

#ifndef _THREAD_H
#define _THREAD_H
#include<iostream>
#include<pthread.h>
#include "queue.h"
namespace THREAD_POOL
{
class CThread_pool;
}
namespace THREAD
{
class CThread_RUN
{
	public:
	virtual void run() = 0;
};
class CThread
  {
   public:
	   CThread(){}
	   CThread(void* arg) {}
	   void start(CThread_RUN* arg)
	   {
	   pthread_create(&m_tid, NULL, thread_func, (void*)arg);
	   }
   private:
	   pthread_t m_tid;
	   static void* thread_func(void* obj)
	   {
		   pthread_detach(pthread_self());
		   CThread_RUN* obj1 = (CThread_RUN*)obj;
		   obj1->run();
	   }
  };
}

#endif


