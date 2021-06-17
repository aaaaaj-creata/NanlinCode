/**
 * creat by nanlin
 * name:指针传值例子
 * date:20210427
 */
#include <iostream>
using namespace std;

void GetMemory1(char **p, int num) {
    *p = (char*)malloc(sizeof(char) * num);
}

char *GetMemory2(int num) {
    char *p = (char*)malloc(sizeof(char) * num);
    return p;
}

char *GetString1(void) {
    char p[] = "hello alex";
    return p; //p是指向"栈内存"的指针,函数调用完毕后销毁
}

char *GetString2(void) {
    char *p = "hello alex"; //可以返回，但是设计概念出错
    return p;
}

int main() {
    //二级指针的方式申请动态空间
    char *str1 = nullptr;
    GetMemory1(&str1, 10);
    strcpy(str1, "hello");
    cout << str1 << endl;
    free(str1);
    //返回值的方式申请动态空间
    char *str2 = nullptr;
    str2 = GetMemory2(20);
    strcpy(str2, "hello world");
    cout << str2 << endl;
    free(str2);
    //错误返回方式
    char *str3 = nullptr;
    str3 = GetString1();
    cout << str3 << endl;
    return 0;
}

