class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string str = s;
        int mn = 3;
        sort(str.begin(),str.end());
        if(s == str) return 0;
        for(int i=0; i<2; i++){
            string first = s.substr(i,n-1+i);
            sort(first.begin(), first.end());
            if(s[n-1] < first[0]){
                return -1;
            }else if(first[n-2] < s[n-1]){
                return 1;
            }
            else{
                return 2;
            }
        }
    }
};