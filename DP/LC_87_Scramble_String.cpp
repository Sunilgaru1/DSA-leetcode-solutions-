class Solution {
public:
    unordered_map<string ,int> mpp;
    bool solve(string a, string b){
        if(a == b) return true;

        if(a.size() != b.size()) return false;
        string key = a + "_" + b;
        if(mpp.find(key) != mpp.end()){
            return mpp[key];
        }
        bool work = false;
        int n = a.size();
        for(int i = 1; i<n; i++){
            bool swap = solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i), b.substr(0,n-i));
            bool noswap = solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i));
            if(swap || noswap){
                work = true;
                break;
            }
        }
        return mpp[key] = work;
    }
    bool isScramble(string s1, string s2) {
        mpp.clear();
        return solve(s1, s2);
    }
};