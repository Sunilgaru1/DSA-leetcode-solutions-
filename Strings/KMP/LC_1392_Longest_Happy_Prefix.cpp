class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        string ans = "";
        vector<int> LPS(n);
        LPS[0] = 0;
        int i = 1;
        int len = 0;
        while(i<n){
            if(s[i] == s[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = LPS[len-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        int x = LPS[n-1];
        for(int i=0; i<x; i++){
            ans += s[i];
        }
        return ans;
    }
};