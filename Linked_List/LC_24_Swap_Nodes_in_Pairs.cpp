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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* curr = head;
        head = head->next;
        ListNode* back = nullptr;

        while(curr!=nullptr && curr->next!=nullptr){
            ListNode* front = curr->next;
            curr->next = front->next;
            if(back) back->next = front;
            front->next = curr;
            back = curr;
            curr = curr->next; 
        }
        return head;
    }
};