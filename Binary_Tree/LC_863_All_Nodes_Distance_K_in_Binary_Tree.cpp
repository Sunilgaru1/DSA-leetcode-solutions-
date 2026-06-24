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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> pr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node  = q.front();
                q.pop();
                if(node->left){
                    pr[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    pr[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        q.push(target);
        unordered_map<TreeNode*,bool> seen;
        seen[target] = true;
        int distance = 0;
        while(distance!=k){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && seen.find(node->left)==seen.end()){
                    seen[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && seen.find(node->right)==seen.end()){
                    seen[node->right] = true;
                    q.push(node->right);
                }
                if(pr.find(node) !=pr.end() && seen.find(pr[node])==seen.end()){
                    seen[pr[node]] = true;
                    q.push(pr[node]);
                }
            }
            distance++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};