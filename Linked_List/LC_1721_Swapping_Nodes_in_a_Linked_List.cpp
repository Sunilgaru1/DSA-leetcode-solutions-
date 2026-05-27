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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* node1 = head;
        ListNode* node2 = head;
        for(int i=1;i<k;i++){
            node1=node1->next;
        }
        ListNode* temp = node1;
        while(temp->next){
            temp=temp->next;
            node2=node2->next;
        }
        int t = node1->val;
        node1->val = node2->val;
        node2->val = t;
        return head;
    }
};