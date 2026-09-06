class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        
        for(int i = 1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        int i = n;
        int j = m;
        string lcs = "";
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                lcs = s1[i-1] + lcs;
                i--;
                j--;
            }else{
                if(t[i-1][j] < t[i][j-1]){
                    j--;
                }else{
                    i--;
                }
            }
        }
        if(lcs == "") return s1 + s2;
        string ans = "";
        i = 0;
        j = 0;
        int k = 0;
        while(k<lcs.size() && i<n && j<m){
            if(lcs[k] == s1[i] && lcs[k] == s2[j]){
                ans += s1[i];
                i++;
                j++;
                k++;
            }
            else if(lcs[k] == s1[i] && lcs[k] != s2[j]){
                ans += s2[j];
                j++;
            }
            else if(lcs[k] != s1[i] && lcs[k] == s2[j]){
                ans += s1[i];
                i++;
            }
            else{
                ans += s1[i];
                ans += s2[j];
                i++;
                j++;
            }
        }
        if(i != n){
            while(i<n){
                ans += s1[i++];
            }
        }
        if(j != m){
            while(j<m){
                ans += s2[j++];
            }
        }
        return ans;
    }
};