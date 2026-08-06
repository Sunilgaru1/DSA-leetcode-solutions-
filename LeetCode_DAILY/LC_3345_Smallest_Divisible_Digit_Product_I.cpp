class Solution {
public:
    int total_product(int num){
        int product = 1;
        while(num){
            int l = num%10;
            num/= 10;
            product *= l;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(total_product(n)%t==0){
                return n;
            }
            n++;
        }
        return 0;
    }
};