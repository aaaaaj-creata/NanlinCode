#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * return the maxfifference
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxDistance(vector<int>& arr) {
        // write code here
        sort(arr.begin(), arr.end());
        int max = 0, num = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            num = arr[i] - arr[i - 1];
            if (num > max)
            {
                max = num;
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 9,3,1,10 };
    cout << s.maxDistance(arr) << endl;

}