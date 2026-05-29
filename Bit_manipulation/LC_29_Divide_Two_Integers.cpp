class Solution {
public:
    int divide(int dividend, int divisor){
        if(dividend==divisor) return 1;
        bool sign = true;
        if(dividend<0 && divisor>0) sign = false;
        else if(dividend>0 && divisor<0) sign = false;

        long long num = llabs((long long)dividend);
        long long div = llabs((long long)divisor);
        long long ans =0;
        while(num>=div){
            int i = 0;
            while(num>=(div<<(i+1))){
                i++;
            }
            num = num - (div<<i);
            ans += (1LL<<i);
        }
        if(ans==(1LL<<31) && sign){
            return INT_MAX;
        }
        else if(ans == (1LL<<31)&& !sign){
            return INT_MIN;
        }
        if(sign==false){
            return -1*ans;
        }
        return ans;
    }
};