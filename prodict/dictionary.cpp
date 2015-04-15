/*************************************************************************
	> File Name: dictionary.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Thu 02 Apr 2015 03:38:40 PM CST
 ************************************************************************/

#include "dictionary.h"
//#include ""
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<string>
#include<string.h>

Diction* Diction::instance_ = NULL;
MutexLock Diction::lock_;

Diction* Diction::getInstance()
{
  if(instance_ == NULL)
  {
     lock_.lock();
     if(instance_ == NULL)
	 {
	 Configure* pconf = Configure::getInstance();
	 string home_path = pconf->getConfigByName("home_path");
	 string data_path = pconf->getConfigByName("data_path");

	 string model_path = pconf->getConfigByName("hmm_gbk_path");
	 string dict_path = pconf->getConfigByName("mp_gbk_path");

	 dict_path = home_path + dict_path;
	 model_path = home_path + model_path;

	 instance_ = new Diction(home_path+data_path, dict_path, model_path);

	 }
	 lock_.unlock();
  }
  return instance_;

}

Diction::Diction(const string &path, const string &dict_path, const string& model_path):dict_map_(), segmentor_(dict_path.c_str(), model_path.c_str()), exclude_set_()
{
loadDictToMap(path);
//buildExcludeSet();
}

Diction::~Diction() {}

void Diction::LoadDictToMap(const string &path)
{
  ifstream ifs(path.c_str());
  if(!ifs.is_open())
  {
  WrITE_STR(string("load gbk dict to map error"));
  throw runtime_error("load dict to map");
  }
  string line;
  while(getline(ifs, line))
  {
  string word;
  int frequency;
  istringstream issm(line);
  issm >> word;
  issm >> frequency;
  dict_map_[word] = frequency;
  //issm.close();
  }

}

void Diction::buildExcludeSet()
{
Configure* pconf = Configure::getInstance();
string home_path = pconf->getConfigByName("home_path");
string exclude_path = pconf->getConfigByName("exclude_path");
string path = home_path + exclude_path;
ifstream ifs;
  if(!open_file(ifs, path.c_str()))
  {
   
  }
}
