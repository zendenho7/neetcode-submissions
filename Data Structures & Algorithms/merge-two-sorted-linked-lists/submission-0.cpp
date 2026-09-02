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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* start = nullptr;

        while(list1 || list2) {
            if((list1 && !list2) || ((list1 && list2) && (list1->val < list2->val))) {
                if(head) head->next = list1;
                else start = list1;
                head = list1;
                //cout << head->val << endl;
                list1 = list1->next;
            }
            else {
                if(head) head->next = list2;
                else start = list2;
                head = list2;
                //cout << head->val << endl;
                list2 = list2->next;
            }
        }

        return start;
    }
};
