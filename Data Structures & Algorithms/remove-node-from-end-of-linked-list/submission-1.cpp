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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = head;
        int size = 0;
        while(dummy) {
            ++size;
            dummy = dummy->next;
        }

        size = size - n;
        dummy = head;
        ListNode* prev = nullptr;
        while(size > 0) {
            --size;
            prev = dummy;
            dummy = dummy->next;
        }
        if(prev) prev->next = dummy->next;
        else if(head->next) head = head->next;
        else head = nullptr;

        return head;
    }
};
