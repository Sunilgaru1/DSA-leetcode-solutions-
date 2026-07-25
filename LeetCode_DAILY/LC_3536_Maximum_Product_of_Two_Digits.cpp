class Solution {
public:
    int maxProduct(int n) {
        int mx = 0;
        int smax = 0;
        if(n/10 ==0 ) return n;
        while(n){
            if(n%10 >= mx){
                smax = mx;
                mx = n%10;
            }
            else if(n%10 >= smax){
                smax = n%10;
            }
            n /= 10;
        }
        return mx*smax;
    }
};