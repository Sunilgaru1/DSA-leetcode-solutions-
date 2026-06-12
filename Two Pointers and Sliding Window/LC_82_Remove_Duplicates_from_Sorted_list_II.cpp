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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(-1,head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* front = head;

        while(front->next != nullptr){
            front = front->next;

            if(front->val != curr->val && curr->next != front){
                prev->next = front;
                curr = front;
            }
            if(front->val != curr->val && curr->next == front){
                prev = curr;
                curr = front;
            } 
        }
        if(front!=curr){
            prev->next = nullptr;
        }
        return dummy->next;
    }
};