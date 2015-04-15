/*************************************************************************
	> File Name: MyConf.h
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 30 Mar 2015 08:22:15 PM CST
 ************************************************************************/

#ifndef __MYCONF_H
#define __MYCONF_H

#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<map>

class MyConf
{
public:
	MyConf(const std::string &filepath);
	MyConf(const char* filepath);
	bool init();
	void show();
	std::map<std::string, std::string> &get_map();

private:
	std::map<std::string, std::string> map_;
	std::ifstream in_;


};

#endif

