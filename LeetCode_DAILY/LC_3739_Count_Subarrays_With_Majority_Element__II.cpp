class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        unordered_map<int,int> mpp;
        long long pre_sum = 0;
        mpp[0] = 1;

        long long count = 0;
        long long left_lowers = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                left_lowers += mpp[pre_sum];
                pre_sum += 1;
            }
            else{
                pre_sum -= 1;
                left_lowers -= mpp[pre_sum];
            }
            mpp[pre_sum] ++;
            count += left_lowers;
        }
        return count;
    }
};