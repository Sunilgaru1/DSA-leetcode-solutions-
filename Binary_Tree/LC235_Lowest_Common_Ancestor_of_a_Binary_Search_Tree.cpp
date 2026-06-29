/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode* left_node = dfs(root->left,p,q);
        TreeNode* right_node = dfs(root->right,p,q);
        if((left_node==p && right_node==q )||(left_node==q&&right_node==p)){
            return root;
        }
        if(left_node) return left_node;
        else return right_node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};