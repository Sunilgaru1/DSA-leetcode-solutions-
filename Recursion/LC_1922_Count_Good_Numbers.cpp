#include <cmath>
class Solution {
public:
    long long mod = 1e9 + 7;
    long long power(int n,long long x){
        if(x==0){
            return 1;
        }
        long long half = power(n,x/2);
        long long result = (half*half)%mod;
        if(x%2==1){
            result = (n * result)%mod;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long a = (n+1)/2;
        long long b = n/2;

        return (power(5,a)*power(4,b))%mod;
    }
};