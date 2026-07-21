class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        vector<int> zeros;
        int i = 0;
        while(i<n){
            if(s[i]=='1') ones++;
            if(s[i]=='0'){
                int st = i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                zeros.push_back(i-st);
            }
            else i++;
        }
        int max_zeros = 0;
        for(int j=1;j<zeros.size();j++){
            max_zeros = max(max_zeros,zeros[j]+zeros[j-1]);
        }
        return ones + max_zeros;
    }
};