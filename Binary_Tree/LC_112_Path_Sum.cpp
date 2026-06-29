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
    bool ans = false;
    void dfs(TreeNode* root,int targetSum){
        if(root==NULL) return;
        if(targetSum==root->val && (root->left==NULL && root->right==NULL)){
            ans = true;
            return;
        }
        dfs(root->left,targetSum-root->val);
        dfs(root->right,targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
};