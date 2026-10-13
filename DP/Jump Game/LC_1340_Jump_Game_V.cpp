class Solution {
public:
    int jump(int i, vector<int>& arr, int d, vector<int> &dp){
        
        if(dp[i] != (-1)) return dp[i];
        dp[i] = 1;
        for(int j = i-1; j>=0 && j>= i-d; j--){
            if(arr[j] >= arr[i]) break;
            dp[i] = max(dp[i], 1 + jump(j, arr, d, dp));
        }
        for(int j = i+1; j<arr.size() && j<=i+d; j++){
            if(arr[j] >= arr[i]) break;
            dp[i] = max(dp[i], 1 + jump(j, arr, d, dp));
        }
        return dp[i];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        int ans = 0;

        for(int i=0; i<n; i++){
            int jumps = jump(i, arr, d, dp);
            ans = max(ans, jumps);
        }
        return ans;
    }
};