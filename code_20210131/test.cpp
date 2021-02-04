#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int sum = 0, min = arr[0];
        for (int i = 0; i < len; ++i) {
            sum += arr[i];
            min = min < arr[i] ? min : arr[i];
        }
        vector<int> v(sum + 1, 0);
        for (int i = 0; i < len; ++i) {
            //{2， 3， 5}
            //i=0--d[10]=2 d[9]=2 d[8]=2 d[7]=2...d[2]=2
            //i=1--d[10]=5 d[9]=5...d[5]=5 d[4]=3 d[3]=3
            //i=2--d[10]=10 d[9]=8 d[8]=8 d[7]=7 d[6]=5 d[5]=5
            for (int j = sum; j >= arr[i]; --j) {
                //逆序判断背包承重中能够放入的数据
                //当数组中只有2的时候，背包承重从2-10都可以放入2的数值
                //当数组中放入2和3的时候，背包承重从5-10可以放入5，3-4放入3，2只能放入2
                //当数组中放入2，3，5时，背包承重10放入10，8-9放入8，7放入7，5-6放入5...
                //dp[j-arr[i]]意思是背包承重为j时，如果已经放置了arr[i]的重量后还能放置的最大重量
                if (v[j] < v[j - arr[i]] + arr[i]) {
                    v[j] = v[j - arr[i]] + arr[i];
                }
            }
        }
        //最后当承重为n时，放入的重量不为n则认为是最大不可求和
        for (int i = min; i <= sum; ++i) {
            if (i != v[i]) {
                return i;
            }
        }
        return sum + 1;
    }
};


//有假币
int main()
{
    int n = 0, sum;
    while (cin >> n)
    {
        int count = 0;
        while (n > 1)
        {
            n = n / 3 + 1 - (n % 3 ^ 3) / 3;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}