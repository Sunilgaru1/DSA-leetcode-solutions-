class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<int> arr;
        long long low = 1;
        long long high = 1LL*(*min_element(coins.begin(),coins.end()))*k; // valid Upper Bound

        while(low < high){
            long long mid = low + (high-low)/2;
            long long cnt = 0;

            for(int m = 1; m<(1<<n); m++){
                    long long lcm = 1;
                    int nCoins = 0;

                    for(int i = 0; i<n; i++){
                        if(m & (1 << i)){
                            nCoins++;
                            long long g = gcd(lcm, (long long)coins[i]);


                            if (lcm / g > mid / coins[i]){
                                lcm = mid + 1;
                                break;
                            }
                            lcm = (lcm/g)*coins[i];
                        }
                    }
                if(lcm <= mid){
                    long long howMany = mid/lcm;

                    if(nCoins%2 == 1) cnt += howMany;
                    else cnt -= howMany;
                }
            }
            if(cnt >= k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};