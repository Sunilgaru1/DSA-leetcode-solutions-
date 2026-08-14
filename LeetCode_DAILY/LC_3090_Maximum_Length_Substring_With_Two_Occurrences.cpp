class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> count(26,0);
        int mx = 0;
        int i=0;
        int j=0;
        while(j<n){
            count[s[j]-'a']++;
            
            while(i<n && count[s[j]-'a']>2){
                count[s[i]-'a']--;
                i++;
            }
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};