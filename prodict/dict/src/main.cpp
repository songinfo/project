/*************************************************************************
	> File Name: main.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 03 Apr 2015 11:49:31 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include "DictProducer.h"
#include "utils.h"

int main(void)
{
	std::string dir = "/home/chao/Desktop/prodict/dict/data";
	std::string storepath = "/home/chao/Desktop/prodict/dict/conf/bible.txt";
	DictProducer dictProducer(dir);
	dictProducer.build_dict();
	//dictProducer.show_dict();
	dictProducer.show_files();

	dictProducer.store_dict(storepath.c_str());
	return 0;
}

