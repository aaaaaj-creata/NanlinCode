/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：实现一个select类，实例化的每个对象都是一个监控对象
*     向外提供简单的接口实现大量描述符的监控
*     添加描述符的监控(在对象中将要监控的描述符保存下来)
*     移除描述符的监控
*     开始监控，并返回就绪的描述符
================================================================*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sys/select.h>
#include "tcpsocket.hpp"

class Select
{
    public:
        Select():_max_fd(-1){
            FD_ZERO(&_rfds);
        }
        bool Add(TcpSocket &sock) {
            int fd = sock.GetFd();//获取到socket描述符
            FD_SET(fd, &_rfds); //将描述符保存下来
            _max_fd = _max_fd > fd ? _max_fd : fd;//重新计算最大的描述符
            return true;
        }
        bool Del(TcpSocket &sock) {
            int fd = sock.GetFd();
            FD_CLR(fd, &_rfds); //从集合中移除描述符
            for (int i = _max_fd; i >= 0; i--) {//从大到小判断,哪个第一个在集合中哪个就是最大的
                if (FD_ISSET(i, &_rfds)) {
                    _max_fd = i;
                    break;
                }
            }
            return true;
        }
        bool Wait(std::vector<TcpSocket> *list, int ms = 3000) {
            fd_set tmp_set;//因为select会修改集合，所以每次使用一个临时的进行监控
            tmp_set = _rfds;
            struct timeval tv;//定义监控等待超时时间
            tv.tv_sec = ms / 1000;//秒
            tv.tv_usec = (ms % 1000) * 1000;//微秒
            int ret = select(_max_fd + 1, &tmp_set, NULL, NULL, &tv);
            if (ret < 0) {
                perror("select error");
                return false;
            }else if (ret == 0) {
                printf("wait timeout\n");
                return false;
            }
            for (int i = 0; i < _max_fd + 1; i++) {//遍历判断哪个描述符就绪了可读
                if (FD_ISSET(i, &tmp_set)) {
                    TcpSocket sock;
                    sock.SetFd(i);
                    list->push_back(sock);
                }
            }
            return true;
        }
    private:
        fd_set _rfds;
        int _max_fd;
};
