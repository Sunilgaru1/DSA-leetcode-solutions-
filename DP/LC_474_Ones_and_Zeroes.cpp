class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int> zero(size);
        vector<int> one(size);

        for(int i = 0; i<size; i++){
            for(char c : strs[i]){
                if(c=='0') zero[i]++;
                else one[i]++;
            }
        }
        vector<vector<vector<int>>> dp(size + 1,vector<vector<int>>(m + 1,vector<int>(n + 1, 0)));
        for(int i = 1; i<=size; i++){
            for(int z = 0; z<=m; z++){
                for(int o = 0; o<=n; o++){

                    int not_take = dp[i-1][z][o];
                    int take = 0;
                    if(z>=zero[i-1] && o>=one[i-1]){
                        take = 1 + dp[i-1][z-zero[i-1]][o-one[i-1]];
                    }
                    dp[i][z][o] = max(take ,not_take);
                }
            }
        }
        return dp[size][m][n];
    }
};