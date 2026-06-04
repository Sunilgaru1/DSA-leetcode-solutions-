
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0 || n==1){
            return n;
        }
        int l = 0;
        int r = 1;
        int maxi = 1;
        while(r!=n){
            int i = l;
            while(i<r){
                if(s[r]==s[i]){
                    l = i+1;
                    break;
                }
                i++;
            }
            maxi = max(r+1-l,maxi);
            r++;
        }
        return maxi;
    }
};
