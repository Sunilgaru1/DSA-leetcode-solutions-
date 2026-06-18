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
    void depth(TreeNode *nodeP,TreeNode *nodeQ,bool &result){
        if(nodeP==NULL && nodeQ==NULL) return;
        if(nodeP==NULL||nodeQ==NULL||(nodeP->val!=nodeQ->val)){
            result = false;
            return;
        }
        if(!result) return;
        depth(nodeP->left,nodeQ->left,result);
        depth(nodeP->right,nodeQ->right,result);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = true;
        depth(p,q,result);
        return result;   
    }
};
