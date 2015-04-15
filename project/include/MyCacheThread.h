/*************************************************************************
	> File Name: MyCacheThread.h
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Tue 07 Apr 2015 05:06:19 PM CST
 ************************************************************************/

#ifndef _MYCACHETHREAD_H_
#define _MYCACHETHREAD_H_

#include "Thread.h"
#include<vector>

class ThreadPool;
class MyCache;
class MyThread;
class MyCacheThread : public Thread
{
public:
	MyCacheThread(const int & num = 12):Thread(), m_pthreads(num)
	{
	
	}
	void get_related(ThreadPool *p);
private:
	void run();
	void scan_cache();
	ThreadPool *m_p;
	std::vector<MyThread*> m_pthreads;

};

#endif

