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
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        long mini = LONG_MAX;
        long smini = LONG_MAX;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val < mini){
                    long temp = mini;
                    mini = node->val;
                    smini = temp;
                }
                else if(node->val > mini && node->val<smini){
                    smini= node->val;
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return smini==LONG_MAX?-1:smini;
    }
};