/*************************************************************************
	> File Name: queue.h
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Sun 29 Mar 2015 10:03:34 PM CST
 ************************************************************************/

#ifndef _QUE_H
#define _QUE_H
#include<queue>
#include<iostream>
#include "mutex.h"
#include "cond.h"

namespace QUEUE
{
class CQueue
  {
   public:
	   class CTask
	   {
		   public:
		   virtual void excute() = 0;
	   };
	   class CPtask
	   {
		public:
			CPtask(CTask* ptr = NULL):m_ptr(ptr){}
			CTask* operator->()
			{
			return m_ptr;
			}
			CTask& operator*()
			{
			return *m_ptr;
			}
		private:
			CTask* m_ptr;

	   };
    CQueue(int capacity = 10):m_capacity(capacity), m_mutex(),m_pro(m_mutex),m_con(m_mutex),m_flag(true) {}
	bool consume(CPtask* task)
	{
	m_mutex.lock();
	while(m_flag && m_queue.empty())
	{
	m_con.wait();
	}
	  if(!m_flag)
	  {
	  m_con.notifyall();
	  return false;
	  }
	  *task = m_que.front();
	  std::cout << "queue consume task " << std::endl;
	  m_que.pop();
	  m_con.notifyall();
	  m_mutex.unlock();
	  return true;
	}
	bool produce(CPtask task)
	{
	m_mutex.lock();
	while(m_flag && m_que.size() >= m_capacity)
	 {
	 m_pro.wait();
	 }
	if(!m_flag)
	{
	m_pro.notifyall();
	return false;
	}
	m_que.push(task);
	m_pro.notifyall();
	m_mutex.unlock();
	return true;
	}
	~CQueue() {}
   private:
	CQueue(const CQueue& obj);
	CQueue& operator=(const CQueue& obj);
	MUTEX::CMutex m_mutex;
	COND::CCond m_pro, m_con;
	bool m_flag;
	int m_capacity;
	std::queue<CPtask> m_que;
  };

}

#endif


