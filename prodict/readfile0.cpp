/*************************************************************************
	> File Name: readfile0.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 03 Apr 2015 10:29:12 AM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<ctype.h>

int main(void)
{
	std::ifstream ifs("py.txt");
	if(!ifs.good())
	{
		std::cout << "open file error !" << std::endl;
		return -1;
	}
	std::ofstream ofs("dict0.txt");
	std::string line;
	while(getline(ifs, line))
	{
	//	std::stringstream ss;
		//ofs << ss << std::endl;
		for(std::size_t i = 0; i != line.size();++i)
		{
			if(isupper(line[i]))
			{
			line[i] = line[i] + 32;
			}
		    if(isalpha(line[i]))
		     {
			
		      ofs << line[i] ;
		     }
		}
		ofs << std::endl;		
	//	std::stringstream ss(line);
    //    ofs << ss;
	}

return 0;
}

