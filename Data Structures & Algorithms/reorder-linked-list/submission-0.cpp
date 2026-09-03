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
    void reorderList(ListNode* head) {
        
        //Split the list in half o(n)
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next) {
            if(fast->next) fast = fast->next;
            if(fast->next) fast = fast->next;
            if(slow) slow = slow->next;
        }

        //Reverse second list
        ListNode* prev = nullptr;
        while(slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        slow = prev;

        //Stitch both lists together
        ListNode* list1 = head;
        ListNode* list2 = slow;
        while(list2->next) {
            ListNode* list1Next = list1->next;
            ListNode* list2Next = list2->next;
            list1->next = list2;
            list2->next = list1Next;
            list1 = list1Next;
            list2 = list2Next;
        }
    }
};
