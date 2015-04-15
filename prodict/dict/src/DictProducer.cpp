/*************************************************************************
	> File Name: DictProducer.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 03 Apr 2015 09:52:59 PM CST
 ************************************************************************/

#include "utils.h"
#include "DictProducer.h"
#include<iostream>
#include<sstream>
#include<fstream>

DictProducer::DictProducer(const char *dir)
	:dir_(dir)
{}
DictProducer::DictProducer(const std::string &dir)
	:dir_(dir)
{}
void DictProducer::build_dict()
{
  get_files();
  for(std::size_t idx = 0; idx != files_.size(); ++idx)
  {
     std::ifstream ifs(files_[idx]);
	 if(!ifs)
	 {
		 std::cout << "stream error, file does not exist or other " <<std::endl;
		 continue;
	 }
	 std::stringstream ss;
	 std::string line;
	 std::vector<std::string> vec_words;
	 while(getline(ifs, line))
	 {
	   ss << line;
	   std::string word;
	   while(ss >> word)
	   {
	     words_process(word, vec_words);
		 auto iter = vec_words.begin();
		 for(; iter != vec_words.end(); ++iter)
		 {
		 push_dict(*iter);
		 }
	   }
	   vec_words.clear();
	   ss.clear();
	 }
	 
  }
  
}

void DictProducer::show_files() const
{
	std::vector<std::string>::const_iterator vit;
	for(vit = files_.begin(); vit != files_.end(); ++vit)
	{
		std::cout << *vit << std::endl;
	}

}

void DictProducer::show_dict() const
{
  auto mit = dict_.begin();
  for(; mit != dict_.end(); ++mit)
  {
  std::cout << mit->first
	  << ' '
	  << mit->second
	  << '\n';
  }
}

void DictProducer::store_dict(const char *filepath)
{
  std::ofstream ofs(filepath);
  if(!ofs)
  {
	  std::cout << "ofstream error" << std::endl;
	  return ;
  }

  std::stringstream ss;
  auto mit = dict_.begin();
  for(; mit != dict_.end(); ++mit)
  {
    int ifreq = mit->second;
	std::string sec;
	ss << ifreq;
	ss >> sec;
	std::string line;
	line += mit->first;
	line += " ";
	line += sec;
	line += "\r\n";
	std::cout << line;
	ofs << line;
	ss.clear();

  }

}

void DictProducer::get_files()
{
::get_files_in_dir(dir_.c_str(), 0, files_);

}
void DictProducer::push_dict(const std::string &word)
{
  auto iter = dict_.find(word);
  if(iter != dict_.end())
  {
    ++(iter->second);
  }
  else
  {
  dict_.insert(make_pair(word, 1));
  }
}

