class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<=1) return n;
        int max_count = 1;
        long long sum = 0;
        int j = 0;
        long long cost = 0;
        for(int i =0;i<n;i++){
            sum+=nums[i];

            cost = (long long)nums[i]*(i-j+1)-sum;

            while(cost>k){
                sum-= nums[j];
                j++;
                cost = (long long)nums[i]*(i-j+1)-sum;
            }
            max_count = max(max_count,i-j+1);
        }
        return max_count;
    }
};