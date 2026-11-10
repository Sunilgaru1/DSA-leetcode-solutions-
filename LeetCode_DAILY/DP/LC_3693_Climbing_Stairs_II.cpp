class Solution {
public:
    // int solve(int i,int n, vector<int> &costs, vector<int> &dp){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
    //     int ans = 1e9;
    //     for(int x=1; x<=3 && i+x<=n; x++){

    //         int temp = solve(i+x,n,costs,dp) + costs[i+x-1] + x*x;
    //         ans = min(ans,temp);
    //     }
    //     return dp[i] = ans;
    // }
    // int climbStairs(int n, vector<int>& costs) {
    //     vector<int> dp(n+1,-1);

    //     return solve(0,n,costs,dp);
    // }


    int climbStairs(int n, vector<int>& costs) {
        int a =0, b=0, c=0;
        for(int i=0; i<n; i++){
            int x = min({a+9,b+4,c+1}) + costs[i];
            a = b;
            b = c;
            c = x;
        }
        return c;
    }
};