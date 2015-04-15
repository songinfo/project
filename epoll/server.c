#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void *client_handler(void *arg);

void do_service(int sockfd);
void do_service2(int sockfd);


int main(int argc, const char *argv[])
{

    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        ERR_EXIT("socket");

    //地址复用
    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt");

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(8976);
    if(bind(listenfd, (struct sockaddr*)&addr, sizeof addr) == -1)
        ERR_EXIT("bind");

    if(listen(listenfd, SOMAXCONN) == -1)
        ERR_EXIT("listen");

    pthread_t cli_thread;
    int cnt = 0;
    while(1)// 循环服务器
    {
        int peerfd = accept(listenfd, NULL, NULL);
        printf("accept success, tcp session No. is %d\n", ++cnt);
        //pthread_create(&cli_thread, NULL, client_handler, peerfd);
        do_service2(peerfd);

        close(peerfd);
    }
    close(listenfd);
    return 0;
}

void *client_handler(void *arg)
{
    int peerfd = (int)arg;

    do_service(peerfd);
    close(peerfd);
    return NULL;
}
void do_service2(int sockfd)
{
        char recvbuf[1024] = {0};
        int nread = read(sockfd, recvbuf, sizeof recvbuf);
        if(nread == -1)
        {
            if(errno == EINTR)
                //continue;
                ERR_EXIT("read");
        }
        else if(nread == 0)
        {
            printf("close ...\n");
            //exit(EXIT_SUCCESS);
        }

        sleep(10);

        write(sockfd, recvbuf, strlen(recvbuf));
        memset(recvbuf, 0, sizeof recvbuf);
}

void do_service(int sockfd)
{
    char recvbuf[1024] = {0};
    while(1)
    {
        int nread = read(sockfd, recvbuf, sizeof recvbuf);
        if(nread == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("read");
        }
        else if(nread == 0)
        {
            printf("close ...\n");
            break;
            //exit(EXIT_SUCCESS);
        }

        sleep(5);

        write(sockfd, recvbuf, strlen(recvbuf));
        memset(recvbuf, 0, sizeof recvbuf);
    }
}




