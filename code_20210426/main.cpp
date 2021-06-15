/**
 * creat by nanlin
 * name:例子实现
 * date:20210426
 */
#include <iostream>
using namespace std;

void func1(int *x) {
    assert(x != nullptr); //传值时assert检测一下
    *x = *x + 10;
}

void func(char a[100]) {
    cout << sizeof(a) << endl;
}

int main() {

/*
    int a = 1;
    //func1(a);
    int *str = (int*)malloc(10 * sizeof(int));
    if (str == nullptr) { //是否申请成功
        cout << "内存申请失败" << endl;
    }
    func1(str);
    cout << *str << endl;
    free(str); //释放
    str = nullptr; //置空
    return 0;
*/

/*
    char a[] = "hello";
    a[0] = 'x';
    cout << a << endl;
    char *b = "hello";
    b[0] = 'x';
    cout << b << endl; //编译器不能发现该错误，但是运行错误
*/
//内容比较
/*
    char a[] = "hello";
    char *b = "helle";
    if (strcmp(a, b) == 0)
    {
        cout << "same" << endl;
    } else {
        cout << "dif" << endl;
    }
*/
    char arr[100];
    cout << sizeof(arr) << endl; //100
    func(arr); //8


    return 0;
}
