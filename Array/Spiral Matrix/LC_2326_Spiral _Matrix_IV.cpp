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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int i = 0,j =0;
        int r = 1;
        int p = 1;
        ListNode* temp = head;
        while(temp != nullptr){
            while(j < n-r+1 && temp != nullptr){
                int p = temp->val;
                temp = temp->next;
                ans[i][j] = p;
                j++;
            }
            j--;
            i++;
            while(i < m-r+1 && temp != nullptr){
                int p = temp->val;
                temp = temp->next;
                ans[i][j] = p;
                i++;
            }
            i--;
            j--;
            while(j >= r-1 && temp != nullptr){
                int p = temp->val;
                temp = temp->next;
                ans[i][j] = p;
                j--;
            }
            j++;
            i--;
            while(i >= r && temp != nullptr){
                int p = temp->val;
                temp = temp->next;
                ans[i][j] = p;
                i--;
            }
            i++;
            j++;
            r++;
        }
        return ans;
    }
};