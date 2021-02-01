#include <iostream>
using namespace std;
#define PAI 3.14
//±äÌ¬ÌøÌ¨½×
class Solution {
public:
    int jumpFloorII(int number) {
        int sum = 1;
        for (int i = 0; i < number-1; i++)
        {
            sum *= 2;
        }
        return sum;
    }

    void catbowl(int catlen,int r)
    {
        double bowllen = 0;
        bowllen = 2 * r * PAI;
        if (catlen < bowllen)
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
    Solution a;
    //cout << a.jumpFloorII(5) << endl;
    double catlen, r;
    while (cin >> catlen >> r)
    {
        a.catbowl(catlen, r);
    }
    return 0;
}