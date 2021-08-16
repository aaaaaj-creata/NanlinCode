#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //1.两数之和 暴力解法
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        int index1 = 0, index2 = 0;
        int diff = 0;
        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            index1 = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (diff == nums[j]) {
                    index2 = j;
                    res[0] = index1;
                    res[1] = index2;
                    return res;
                }
            }
        }
        return res;
    }

    //1.两数之和 最佳解法 哈希映射
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            auto it = hashtable.find(diff);
            //找到了,说明哈希表中有数值和nums[i]加起来等于target
            if (it != hashtable.end()) {
                return { it->second, i };
            }
            //没找到则在哈希表中插入
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> test = { -1, -2, -3, -4, -5 };
    vector<int> res(2, 0);
    int target = -8;
    //res = s.twoSum1(test, target);
    res = s.twoSum2(test, target);
    return 0;
}