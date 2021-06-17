/**
 * creat by nanlin 20210428
 * name: 重载、覆盖、隐藏例子
 */
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void fun1(float x) { //覆盖，函数原型完全一致
        cout << "Base::fun1(float)" << x << endl;
    }

    void fun2(float x) { //隐藏，函数名一致，参数不同，不加virtual
        cout << "Base::fun2(float)" << x << endl;
    }

    virtual void fun3(float x) { //隐藏，函数名一致，参数不同，加virtual
        cout << "Base::fun4(float)" << x << endl;
    }

    void fun4(float x) { //隐藏，函数名一致，参数相同同，不加virtual，如果加了virtual就是覆盖
        cout << "Base::fun3(float)" << x << endl;
    }



//    virtual void fun5(float x) { //隐藏，函数名一致，参数不同，加virtual
//        cout << "Base::fun2(float)" << x << endl;
//    }
};

class Derived : public Base
{
public:
    virtual void fun1(float x) {
        cout << "Derived::fun1(float)" << x << endl;
    }

    void fun2(int x) {
        cout << "Derived::fun2(int)" << x << endl;
    }

    void fun3(int x) {
        cout << "Derived::fun4(int)" << x << endl;
    }

    void fun4(float x) {
        cout << "Derived::fun3(float)" << x << endl;
    }



//    void fun5(int x) {
//        cout << "Derived::fun2(int)" << x << endl;
//    }
};
int main() {
    Derived d;
    Base *pb = &d;
    Derived *pd = &d;

    pb->fun1(3.14f); //Derived::fun1(float)3.14
    pd->fun1(3.14f); //Derived::fun1(float)3.14

    pb->fun2(3.14f); //Base::fun2(float)3.14
    pd->fun2(3.14f); //Derived::fun2(int)3

    pb->fun3(3.14f); //Base::fun3(float)3.14
    pd->fun3(3.14f); //Derived::fun3(int)3

    pb->fun4(3.14f); //Base::fun3(int)3.14
    pd->fun4(3.14f); //Derived::fun3(int)3.14



    return 0;
}
