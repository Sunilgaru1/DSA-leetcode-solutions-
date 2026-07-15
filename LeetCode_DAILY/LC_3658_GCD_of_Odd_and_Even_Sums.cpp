class Solution {
public:
    int gcd(int sumOdd,int sumEven){
        while (sumEven!=0){
            int remainder = sumOdd%sumEven;
            sumOdd = sumEven;
            sumEven = remainder;
        }
        return sumOdd;
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n*(n+1);

        return gcd(sumOdd,sumEven);
    }
};