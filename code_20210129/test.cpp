#include <iostream>
using namespace std;

class Solution {
public:
    //不用加减乘除做加法
    int Add(int num1, int num2)
    {
        int a, b=1;
        while (b != 0)
        {
            a = num1 ^ num2;
            b = (num1 & num2) << 1;
            num1 = a;
            num2 = b;
        }
        return a;
    }
    void judge(int a, int b, int c)
    {
        if (a + b > c && a + c > b && b + c > a)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
};

int main()
{
    Solution s;
    //cout << s.Add(5, 12) << endl;
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        s.judge(a, b, c);
    }
    return 0;
}