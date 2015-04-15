/*************************************************************************
	> File Name: DictProducer.h
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 03 Apr 2015 09:30:18 PM CST
 ************************************************************************/

#ifndef _DICTPRODUCER_H
#define _DICTPRODUCER_H

#include<iostream>
#include<string>
#include<vector>
#include<map>

class DictProducer
{
public:
	DictProducer(const char *dir);
	DictProducer(const std::string &dir);

	void build_dict();
	void show_files() const;
	void show_dict() const;
	void store_dict(const char *filepath);
private:
	void get_files();
	void push_dict(const std::string &word);
private:
	std::string dir_;
	std::vector<std::string> files_;
	std::map<std::string, int> dict_;

};

#endif 

