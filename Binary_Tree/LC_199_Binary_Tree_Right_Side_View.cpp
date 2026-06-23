/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void find(TreeNode* node,int n,vector<int> &ans){
        if(node==NULL) return;
        
        if(n==ans.size()){
            ans.push_back(node->val);
        }
        find(node->right,n+1,ans);
        find(node->left,n+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        find(root,0,ans);
        return ans;
    }
};