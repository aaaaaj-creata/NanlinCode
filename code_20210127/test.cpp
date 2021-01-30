//Êý¸ù
#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
    int n = 0,sum = 0;
    string num;
    while (cin >> num)
    {
        int len = num.size();
        while (len > 1)
        {
            sum = 0;
            for (int i = 0; i < len; i++)
            {
                sum += (num[i] - '0');
            }
            num = to_string(sum);
            len = num.size();
        }
        n = num[0] - '0';
        cout << n << endl;
    }
    return 0;
}
#endif