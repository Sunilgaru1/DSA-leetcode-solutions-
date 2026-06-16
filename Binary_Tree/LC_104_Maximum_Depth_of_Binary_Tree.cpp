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
    int depth(TreeNode *node,int n){
        if(node==NULL) return n;

        int left = depth(node->left,n+1);

        int right = depth(node->right,n+1);

        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
         
        return depth(root,0);
    }
};