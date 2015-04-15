/*************************************************************************
	> File Name: MyConf.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Mon 30 Mar 2015 08:27:13 PM CST
 ************************************************************************/

#include "MyConf.h"
#include<iostream>
#include<utility>
#include<sstream>

MyConf::MyConf(const std::string &filepath)
	:in_(filepath.c_str())
{}
MyConf::MyConf(const char* filepath)
	:in_(filepath)
{}


bool MyConf::init()
{
if(!in_)
  {
	  std::cout << "file read error " << std::endl;
	  return false;
  }

std::string line;
while(getline(in_, line))
{

	std::string key, value;
	std::stringstream ss(line);
	ss >> key >> value;
	map_.insert(make_pair(key, value));

}
    in_.close();
	return true;

}

void MyConf::show()
  {
	  std::map<std::string, std::string>::const_iterator mit;
	  for(mit = map_.begin(); mit != map_.end(); ++mit)
	  {
		  std::cout << mit->first
			  <<"----->"
			  << mit->second
			  <<std::endl;
	  }

}

std::map<std::string, std::string> &MyConf::get_map()
{
return map_;
}
