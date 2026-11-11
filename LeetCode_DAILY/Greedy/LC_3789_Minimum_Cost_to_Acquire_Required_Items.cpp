class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long ans = 0;
        
        int min_n = min(n1,n2);

        ans += 1LL*min_n*min(cb, c1+c2);

        if(n1-min_n){
            ans += 1LL*(n1-min_n)*min(cb,c1);
        }
        if(n2-min_n){
            ans += 1LL*(n2-min_n)*min(cb,c2);
        }
        return ans;
    }
};