/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return nullptr;

        unordered_map<Node*, Node*> oldToCopy;
        
        //2 Pass approach, copy the linked list first before random
        Node* newHead = new Node(head->val);
        Node* newDummy = newHead;
        Node* dummy = head;
        while(dummy->next) {
            oldToCopy[dummy] = newDummy;
            dummy = dummy->next;
            newDummy->next = new Node(dummy->val);
            newDummy = newDummy->next;
        }
        oldToCopy[dummy] = newDummy;

        //Second pass setting random
        dummy = head;
        newDummy = newHead;
        while(dummy) {
            newDummy->random = dummy->random ? oldToCopy[dummy->random] : nullptr;
            newDummy = newDummy->next;
            dummy = dummy->next;
        }

        return newHead;
    }
};
