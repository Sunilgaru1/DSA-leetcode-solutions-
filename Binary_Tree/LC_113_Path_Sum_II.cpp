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
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(TreeNode* root,int targetSum){
        if(root==NULL) return;
        temp.push_back(root->val);
        if(targetSum==root->val && root->left==NULL && root->right==NULL){
            ans.push_back(temp);
        }
        else{
            dfs(root->left,targetSum-root->val);
            dfs(root->right,targetSum-root->val);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
};