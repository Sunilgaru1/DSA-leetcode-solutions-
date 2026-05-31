class Solution {
public:
    void GP1(vector<string> &ans,int i,int j,int n,string temp){
        if(i==n && j==n){
            ans.push_back(temp);
            return;
        }
        if(i<n){
            GP1(ans,i+1,j,n,temp+"(");}
        if(j<i){
            GP1(ans,i,j+1,n,temp+")");
        }
    }

    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string temp = "(";
    
        GP1(ans,1,0,n,temp);
        return ans;
    }
};