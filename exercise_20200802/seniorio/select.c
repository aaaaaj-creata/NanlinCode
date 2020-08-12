#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/select.h>

int main()
{
    fd_set rfds;//定义可读事件集合
    FD_ZERO(&rfds);//清空事件集合
    while(1) {
        FD_SET(0, &rfds);//将标准输入添加到集合中进行监控
        //select(最大描述符+1，可读事件集合，可写事件集合，异常事件集合，超时等待时间)
        int ret = select(1, &rfds, NULL, NULL, NULL);
        if (ret < 0) {
            perror("select error");
            continue;
        }else if (ret == 0) {
            printf("wait timeout\n");
            continue;
        }
        printf("有描述符就绪了~~这时候可以对就绪描述符进行操作了~~\n");
        //有可能一次监控有多个描述符就绪了事件
        for (int i = 0; i < 1; i++) {//当前只有一个描述符其实可以不要这个，有多个描述符监控
            if (FD_ISSET(0, &rfds)) {//通过判断0号描述符是否在集合中，确定是否就绪
                char buf[1024] = {0};
                int ret = read(0, buf, 1023);
                if (ret < 0) {
                    perror("read error");
                    return -1;
                }
                printf("read buf:[%s]\n", buf);
            }
        }
    }
    return 0;
}
