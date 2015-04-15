/*************************************************************************
	> File Name: main.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 30 Mar 2015 08:39:58 PM CST
 ************************************************************************/

#include<string>
#include<map>
#include<sstream>
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include "MyConf.h"
#include "Socket.h"
#include "InetAddress.h"
#include "ThreadPool.h"
#include "epoll_t.h"
#include "sysutil.h"
#include "MyDict.h"

void foo(const char* buf, size_t cnt, int fd)
{
	std::cout << buf <<"==> size: " << cnt << std::endl;
//	write(fd, buf, cnt);
}

int main(void)
{
	//
	std::string filepath = "/home/chao/Desktop/project/conf/my.conf";
	MyConf myconf(filepath);
	bool initFlag = myconf.init();
	if(initFlag)
	{
	myconf.show();
	}
	
//	myconf.show();

	std::map<std::string, std::string> &my_map = myconf.get_map();
    std::string dictpath = my_map["my_dict"];
	std::cout << dictpath << std::endl;

	MyDict *pMydict = MyDict::createInstance(dictpath.c_str());

	std::string sip = my_map["server_ip"];
	std::string sport = my_map["server_port"];
	std::stringstream ss(sport);
	int iport = 0;
	ss >> iport;
	std::cout << iport << std::endl;

	ThreadPool thp(50, 10, (*pMydict));
	thp.start();

	InetAddress inetAddr(sip, iport);
	Socket mySocket;
	mySocket.init(0, inetAddr);

	int listenfd = mySocket.get_sockfd();

	epoll_t et;
	epoll_init(&et, listenfd, &foo );
	while(1)
	{
		epoll_loop(&et);
		epoll_handle_fd(&et, thp);

	}

	epoll_destroy(&et);

	return 0;
}
