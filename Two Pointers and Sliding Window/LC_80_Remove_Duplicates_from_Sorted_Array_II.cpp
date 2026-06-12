class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int count = 1;
        int k = 1;
        for(int j = 1;j<nums.size();j++){
            if(nums[j]==nums[i]){
                if(count<2){
                    i++;
                    nums[i] = nums[j];
                    count++;
                }
            }
            else{
                i++;
                nums[i] = nums[j];
                count = 1;
            }
        }
        return i+1;
    }
};