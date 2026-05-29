class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        //n<<k = n * 2^k
        return (n & (n-1))==0;
    
    }
};