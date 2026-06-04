class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int n = x^y;
        while(n){
            count += n & 1;
            n>>=1;
        }
        return count;
    }
};
