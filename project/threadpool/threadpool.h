/*************************************************************************
	> File Name: threadpool.h
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sun 29 Mar 2015 09:06:49 PM CST
 ************************************************************************/

#ifndef _THREAD_POOL
#define _THREAD_POOL
#include<vector>
#include "thread.h"
#include "queue.h"
namespace THREAD
{
class CThread;
class CThread_RUN;

}
namespace THREADPOOL
{
class CThread_pool
   {
	public:
		CThread_pool(int nworkers = 10, int ncapacity = 10)
			:m_thread_pool(nworkers),m_que(ncapacity)
		{}
		void on(THREAD::CThread_RUN* thread_run)
		{
		if(m_flag == false)
		{
		m_flag = true;
		}
		std::vector<THREAD::CThread>::iterator iter = m_thread_pool.begin();
		for(iter; iter != m_thread_pool.end(); iter++)
		{
		iter->start(thread_run);
		}
		}
		void off()
		{
		if(m_flag == true)
		  {
			  m_flag = false;
		  }
		}
		~CThread_pool()
		{}
		QUEUE::CQueue m_que;
	private:
		bool m_flag;
		std::vector<THREAD::CThread> m_thread_pool;
		CThread_pool(const CThread_pool& obj)
		{}
		CThread_pool& operator=(const CThread_pool& obj)
		{}
   };
}

#endif


