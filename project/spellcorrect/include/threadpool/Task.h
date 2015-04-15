#ifndef _TASK_H
#define _TASK_H

#include <string>

class Task
{
public:
	Task(const std::string &expr, int sockfd);
	Task(const char *expr, int sockfd);

	void execute();

private:
	std::string expr_;
	int sockfd_;
};

#endif
