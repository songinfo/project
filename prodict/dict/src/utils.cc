#include "utils.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#include <iostream>

void get_files_in_dir(const char *dir,
		int depth,
		std::vector<std::string> &files)
{
	if(NULL == dir)
	{
		fprintf(stderr, "dir param error\n");
		return;
	}
	DIR *pDir = opendir(dir);
	if(NULL == pDir)
	{
		fprintf(stderr, "cannot open directory:%s\n", dir);
		return ;
	}
	
	chdir(dir);
	struct dirent *pEntry;
	struct stat   statbuf;
	while(NULL != (pEntry = readdir(pDir)))
	{
		stat(pEntry->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(".", pEntry->d_name) == 0 ||
			   strcmp("..", pEntry->d_name) == 0)
			{	continue;	}

			printf("%*s%s\n", depth, "", pEntry->d_name);
			get_files_in_dir(pEntry->d_name, depth + 4, files);
		}
		else
		{
			printf("%*s%s\n", depth, "", pEntry->d_name);
			std::string filename(dir);
			filename += '/';
			filename += pEntry->d_name;
			files.push_back(filename);
		}
	}
}

std::string &cut_space_front_back(std::string &word)
{
	std::size_t sz = word.size();
	if(sz > 0)
	{
		std::size_t ipos = word.find_first_not_of(' ');
		if(ipos != std::string::npos)
			word = word.substr(ipos);
		else
		{
			word = "";
			return word;
		}

		ipos = word.find_last_not_of(' ');
		word = word.substr(0, ipos + 1);
	}
	return word;
}

std::string &upper_to_lower(std::string &word)
{
	std::size_t sz = word.size();
	if(sz > 0)
	{
		std::string::iterator sit = word.begin();
		for(; sit != word.end(); ++sit)
		{
			char ch = *sit;
			if(isupper(ch))
			{
				*sit = tolower(*sit);
			}
		}
	}
	return word;
}


void words_process(std::string &words, std::vector<std::string> &words_vec)
{
#if 1
	std::size_t sz = words.size();
	if(sz <= 0)
	{
		return;
	}
	
	words = upper_to_lower(words);

	std::string word;
	std::string::iterator sit1 = words.begin();
	std::string::iterator sit2; 
	for(sit1 = words.begin(); sit1 != words.end(); ++sit1)
	{
		if(isalpha(*sit1))
		{//当指针1指向字母时，保存其位置
			for(sit2 = sit1 + 1; sit2 != words.end(); ++sit2)
			{
				if(isalpha(*sit2))
				{//当指针2指向字母时，扫描下一个字符
					continue;	
				}
				else
				{//当指针2指向非字母时，截取单词，并放入数组中
					std::size_t cnt = sit2 - sit1;
					std::size_t ipos = sit1 - words.begin();
					word = words.substr(ipos, cnt);
					words_vec.push_back(word);
					sit1 = sit2;
					break;
				}
			}
		}
	}
#endif
}
