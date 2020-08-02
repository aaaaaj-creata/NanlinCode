/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：封装一个Epoll类型，每个实例化的对象都是一个监控对象
*     只需要向外提供简单的接口，就能事件描述符的监控
================================================================*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sys/epoll.h>
#include "tcpsocket.hpp"

class Epoll
{
    public:
        Epoll():_epfd(-1){
            _epfd = epoll_create(1);
            if (_epfd < 0) {
                perror("epoll create error");
                exit(-1);
            }
        }
        bool Add(TcpSocket &sock) {
            int fd = sock.GetFd();
            struct epoll_event ev;
            ev.data.fd = fd;//通常监控的描述符与data中的fd相同，则描述符就绪时操作的就是data.fd
            ev.events = EPOLLIN | EPOLLET;//EPOLLIN-可读 | EPOLLOUT-可写 | EPOLLET-边缘触发
            int ret = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &ev);
            if (ret < 0) {
                perror("epoll_ctl add error");
                return false;
            }
            return true;
        }
        bool Del(TcpSocket &sock) {
            int fd = sock.GetFd();
            int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, NULL);
            if (ret < 0) {
                perror("epoll_ctl del error");
                return false;
            }
            return true;
        }
        bool Wait(std::vector<TcpSocket> *list,  int timeout=3000) {
            struct epoll_event evs[10];
            int ret = epoll_wait(_epfd, evs, 10, timeout);
            if (ret < 0) {
                perror("epoll wait error");
                return false;
            }else if (ret == 0) {
                printf("epoll wait timeout\n");
                return false;
            }
            for (int i = 0; i < ret; i++) {
                if (evs[i].events & EPOLLIN) {//判断就绪的事件是否是可读事件
                    TcpSocket sock;
                    sock.SetFd(evs[i].data.fd);
                    list->push_back(sock);
                }
            }
            return true;
        }
    private:
        int _epfd;
};
