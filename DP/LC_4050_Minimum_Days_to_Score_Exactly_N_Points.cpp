class Solution {
public:
    int minDays(int n) {
        
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int s =0; s<=n; s++){
            if(dp[s]==1e9){
                continue;
            }
            for(int k = 1; k*(k+1)/2 <= n-s; k++){
                int score = k*(k+1)/2;

                dp[score + s] = min(dp[score+s], dp[s]+k+1);
            }
        }
        return dp[n]-1;
    }
};