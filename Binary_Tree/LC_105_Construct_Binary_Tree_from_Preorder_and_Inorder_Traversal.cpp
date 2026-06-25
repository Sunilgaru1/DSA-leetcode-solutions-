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
    TreeNode* solve_tree(vector<int>& preorder,int prst,int prend,vector<int>& inorder,int inst,int inend,unordered_map<int,int> &inMap){
        if(prst>prend || inst>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prst]);
        int inRoot = inMap[root->val];
        int left = inRoot - inst;
        root->left = solve_tree(preorder,prst+1,prst+left,inorder,inst,inRoot-1,inMap);
        root->right= solve_tree(preorder,prst+left+1,prend,inorder,inRoot+1,inend,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;

        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = solve_tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
};