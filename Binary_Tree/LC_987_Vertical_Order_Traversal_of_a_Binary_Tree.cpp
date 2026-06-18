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
    void path(TreeNode* node, int n, int m,vector<tuple<int,int,int>> &nodes){
        if(node==NULL) return;
        nodes.push_back({m, n, node->val});
        path(node->left,n+1,m-1,nodes);
        path(node->right,n+1,m+1,nodes);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;
    
        path(root,0,0,nodes);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        if(nodes.empty()) return ans;

        int prevCol = get<0>(nodes[0]);
        ans.push_back({});

        for(auto &t : nodes){
            int col = get<0>(t);
            int val = get<2>(t);

            if(col != prevCol){
                ans.push_back({});
                prevCol = col;
            }

            ans.back().push_back(val);
        }
        return ans;
    }
};