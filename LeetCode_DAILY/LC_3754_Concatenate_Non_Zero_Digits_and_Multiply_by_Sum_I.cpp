class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long ans = 0;
        string m = to_string(n);
        for(int i=0;i<m.size();i++){
            if(m[i]=='0'){
                continue;
            }
            long long x = m[i]-'0';
            ans = ans*10 + x;
            sum += x;
        }
        return 1LL*ans*sum;
    }
};