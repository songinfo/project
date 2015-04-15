/*************************************************************************
	> File Name: main.c
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Fri 27 Mar 2015 10:19:59 PM CST
 ************************************************************************/

#include "epoll_t.h"
#include "sysutil.h"

void foo(const char* buf, size_t cnt, int peerfd)
{
printf("receive msg : %d \n", cnt);
send_msg_with_len(peerfd, buf, cnt);
}
int main(int argc, char const* argv[])
{
int listenfd = tcp_server("192.168.44.136", 9981);

epoll_t et;
epoll_init(&et, listenfd, &foo);
while(1)
 {
 epoll_loop(&et);
 epoll_handle_fd(&et);

 }
epoll_destroy(&et);
close(listenfd);

return 0;
}
