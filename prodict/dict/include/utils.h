/*************************************************************************
	> File Name: utils.h
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 03 Apr 2015 09:38:57 PM CST
 ************************************************************************/

#ifndef _UTILS_H
#define _UTILS_H

#include<iostream>
#include<string>
#include<vector>

void get_files_in_dir(const char *dir, 
		int depth, 
		std::vector<std::string> &files);

void words_process(std::string &word, std::vector<std::string> &words_vec);
std::string &upper_to_lower(std::string &word);
std::string &cut_space_front_back(std::string &word);

#endif

