class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1);
        int count =0;
        for(int i=2;i<n;i++){
            prime[i] = true;
        }

        for(int i =2;i*i<n;i++){
            if(prime[i]==0){
                continue;
            }
            for(int j=i*i;j<n;j+=i){
                prime[j] =false;
            }
        }
        for(int i= 2;i<n;i++){
            if(prime[i]==true){
                count++;
            }
        }
        return count;
    }
};