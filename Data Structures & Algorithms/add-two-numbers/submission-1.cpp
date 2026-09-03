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
        ListNode* dummyL1 = l1;
        ListNode* prev = nullptr;
        bool carry = false;
        while(dummyL1 || l2 || carry) {

            int l1val = dummyL1 ? dummyL1->val : 0;
            int l2val = l2 ? l2->val : 0;
            int sum = l1val + l2val + (carry ? 1 : 0);
            if(sum > 9) {
                carry = true;
                sum -= 10;
            }
            else {
                carry = false;
            }

            if(dummyL1) dummyL1->val = sum;
            else {
                prev->next = new ListNode(sum);
                prev = prev->next;
            }

            if(dummyL1) prev = dummyL1;
            if(dummyL1) dummyL1 = dummyL1->next;
            if(l2) l2 = l2->next;
        }
        return l1;
    }
};
