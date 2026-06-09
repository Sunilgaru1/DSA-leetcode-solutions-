class Solution {
public:
    int lesser_equalSubarray(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int l = 0;
        int r = 0;
        int sum = 0;
        int count = 0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count += (r-l+1); // I missed
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count_lesser_equal = lesser_equalSubarray(nums,goal);
        int count_lesser_equal2 = lesser_equalSubarray(nums,goal-1);

        return (count_lesser_equal-count_lesser_equal2);
    }
};