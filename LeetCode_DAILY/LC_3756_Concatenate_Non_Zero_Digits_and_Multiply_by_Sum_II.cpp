class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos;
        vector<long long> prefHash(1, 0);
        vector<long long> prefSum(1, 0);

        for(int i=0; i<n; i++){
            if(s[i]!='0'){
                int d = s[i]-'0';
                pos.push_back(i);
                prefHash.push_back((prefHash.back()*10+d)%MOD);
                prefSum.push_back(prefSum.back() + d);
            }
        }

        int m = pos.size();

        vector<long long> pow10(m+1, 1);
        for(int i=1; i<=m; i++) pow10[i] = (pow10[i-1]*10)%MOD;

        vector<int> ans;

        for(auto &q : queries){
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) -pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) -pos.begin() -1;

            if(L > R){
                ans.push_back(0);
                continue;
            }

            int k = R -L +1;

            long long sum = prefSum[R+1] - prefSum[L];

            long long x = (prefHash[R+1] -prefHash[L]*pow10[k])%MOD;
            if(x<0) x+=MOD;

            ans.push_back((x*(sum%MOD))%MOD);
        }
        return ans;
    }
};