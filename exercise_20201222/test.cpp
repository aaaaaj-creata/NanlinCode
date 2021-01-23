#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//汉明距离
class Solution {
public:
    vector<int> binary(int n)
    {
        vector<int> s(32,0);
        int temp = 0, i = 0;
        while (n != 0)
        {
            temp = n % 2;
            s[i] = temp;
            n = n / 2;
            i++;
        }
        return s;
    }

    int hammingDistance(int x, int y) {
        vector<int> s1 = binary(x);
        vector<int> s2 = binary(y);
        int sum = 0, i=0;
        while (i < s1.size())
        {
            if (s1[i] != s2[i])
            {
                sum++;
            }
            i++;
        }
        return sum;
    }
};

int main()
{
    Solution a;
    int sum = 0;
    sum = a.hammingDistance(4, 1);
    cout << sum << endl;
    return 0;
}
#endif

#if 0
//合并二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
        {
            return t2;
        }
        if (t2 == NULL)
        {
            return t1;
        }
        t1->val = t1->val + t2->val;

        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};
#endif

#if 0
//字符集合
int main()
{
    string s;
    while (getline(cin, s))
    {
        vector<int> v(130, 0);
        int i = 0;
        while (i < s.size())
        {
            v[s[i]] = 1;
            i++;
        }
        i = 0;
        while (i < s.size())
        {
            if (v[s[i]] == 1)
            {
                cout << s[i];
                v[s[i]] = 0;
            }
            i++;
        }
        cout << endl;
    }
    return 0;
}

#endif

//元素查找

class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        // write code here
        if (n < 1)
        {
            return -1;
        }
        int left = 0;
        int right = n - 1;
        int mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (A[mid] == x)
            {
                return mid;
            }

            if (A[mid] <= A[right])
            {
                if (A[mid] < x)
                {
                    if (A[right] >= x) left = mid + 1;
                    else right = mid;
                }
                else left = mid;
            }
            if (A[mid] > A[right])
            {
                if (A[mid] <= x)
                {
                    left = mid + 1;
                }
                else
                {
                    if (A[right] >= x)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid;
                    }
                }
            }
        }
        return -1;
    }
};