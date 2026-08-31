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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head->next;
        int i = 1;
        while(temp->next != NULL){
            if(head->val > temp->val && temp->val < temp->next->val){
                ans.push_back(i);
            }
            else if(head->val < temp->val && temp->val > temp->next->val){
                ans.push_back(i);
            }
            head = temp;
            temp = temp->next;
            i++;
        }
        if(ans.size()<2){
            return {-1,-1};
        }
        int b = INT_MAX;
        for(int i = 1;i<ans.size(); i++){
            b = min(b,ans[i]-ans[i-1]);
        }

        return {b,ans[ans.size()-1]-ans[0]};
    }
};