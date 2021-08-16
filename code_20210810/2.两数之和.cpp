/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1); //存放结果
        ListNode* cur = res;
        int sum = 0; //相加结果
        bool carry = false; //是否进位
        while (l1 != nullptr || l2 != nullptr) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry) { //进位
                sum++;
            }
            //存放当前位的相加结果
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            //判断下一次是否需要进位
            if (sum >= 10) {
                carry = true;
            }
            else {
                carry = false;
            }
        }
        if (carry) {
            cur->next = new ListNode(1);
        }

        return res->next;
    }
};