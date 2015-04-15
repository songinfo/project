#include "Task.h"
#include <iostream>

Task::Task(const std::string &expr, int sockfd)
	: expr_(expr), 
	  sockfd_(sockfd)
{
}

Task::Task(const char *expr, int sockfd)
	: expr_(expr),
	  sockfd_(sockfd)
{
}

void Task::execute()
{
	std::cout << "task is executing!" << std::endl;
	std::cout << "-->>" << expr_ << std::endl;
}
