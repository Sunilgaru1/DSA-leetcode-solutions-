class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        while(l<n && r<n){
            if(nums[r]>=minK && nums[r]<=maxK){
                r++;
            }else{
                long long len = r-l;
                ans += (len)*(len+1)/2;
                r++;
                l = r;
            }
        }
        long long len = r-l;
        ans += (len)*(len+1)/2;
        return ans;
    }
};