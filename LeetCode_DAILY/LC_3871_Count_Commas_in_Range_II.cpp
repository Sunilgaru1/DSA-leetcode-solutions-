class Solution {
public:
    long long countCommas(long long n) {
        if(n<1e3) return 0;

        long long total = 0;
        long long base = 1000;
        while(base <= n){
            total += (n-base+1);
            base *= 1000;
        }
        return total;
    }
};