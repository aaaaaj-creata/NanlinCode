/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：这个demo以标准输入为例，演示非阻塞操作的基本实现 
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main()
{
    //设置非阻塞属性--步骤
    //1. 获取原有属性
    int flag = fcntl(0, F_GETFL, 0);
    //2. 在原有属性之上添加非阻塞属性
    fcntl(0, F_SETFL, flag | O_NONBLOCK);
    while(1) {
        char tmp[1024] = {0};
        int ret = read(0, tmp, 1023);//从标准输入读取数据
        if ( ret < 0 ) {
            if (errno == EAGAIN) {//这个错误编号表示当前没有数据，不满足IO条件
                printf("This descriptor has no data\n");
                sleep(1);
                continue;//可以遍历所有描述符逐个进行操作,不会因为一个描述符无法操作而阻塞
            }
            perror("read error");
            return -1;
        }
        printf("%s\n", tmp);
    }
    return 0;
}
