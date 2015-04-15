#include <iostream>
#include <string>
#include <vector>
#include "DictProducer.h"
#include "utils.h"

int main(void)
{
	std::string dir = "/home/luo/project/produce_dict/data";
	std::string storepath = "/home/luo/project/produce_dict/conf/dict.dat";
	DictProducer dictProducer(dir);
	dictProducer.build_dict();
	//dictProducer.show_dict();
	dictProducer.show_files();
	
	dictProducer.store_dict(storepath.c_str());
	return 0;
}

int test0()
{
#if 1
	std::vector<std::string> words_vec;
	std::string str = "    << >>   This iS a ? abc dde @@abc ### TesT!     ";
	str = cut_space_front_back(str);
	std::cout << str << ", len = " << str.size() << std::endl;
	

	str = upper_to_lower(str);
	std::cout << str << ", len = " << str.size() << std::endl;
	std::cout << str << std::endl;

	words_process(str, words_vec);
	auto iter = words_vec.begin();
	for(; iter != words_vec.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}


	str = "     ";
	str = cut_space_front_back(str);
	std::cout << str << std::endl;

#endif
	return 0;
}
