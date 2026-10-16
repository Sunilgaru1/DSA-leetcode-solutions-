class Solution {
public:
    vector<int> score(string &s, int i, int j, vector<vector<vector<int>>> &dp){
        if(!dp[i][j].empty()) return dp[i][j];

        vector<int> ans;
        
        for(int k=i; k<=j; k++){
            if(s[k] == '+' || s[k] == '-' || s[k] == '*'){
                vector<int> left = score(s, i, k-1, dp);
                vector<int> right = score(s, k+1, j, dp);
                for(int l : left) {
                    for(int r : right) {
                        if(s[k] == '+') ans.push_back(l+r);
                        else if(s[k] == '-') ans.push_back(l-r);
                        else ans.push_back(l*r);
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(s.substr(i,j-i+1)));
        }
        return dp[i][j] = ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n));
        return score(expression, 0, n-1, dp);
    }
};