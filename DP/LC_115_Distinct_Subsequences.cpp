// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();

//         vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));

//         for(int i = 0; i<=n; i++){
//             dp[i][0] = 1; // we can make empty string from any s
//         } 

//         for(int i =1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(s[i-1]==t[j-1]){
//                     dp[i][j] = dp[i-1][j] + dp[i-1][j-1]; // we can choose to take a char or not 
//                 }else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = m; j >= 1; j--){
                if(s[i-1] == t[j-1]){
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[m];
    }
};