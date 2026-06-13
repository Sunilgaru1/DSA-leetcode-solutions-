class Solution {
public:
    string removeDigit(string nums, char digit) {
        int n = nums.size();
        int x = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] == digit){
                x = i;
                if(i + 1 < n && nums[i + 1] > digit){
                    nums.erase(nums.begin() + i);
                    return nums;
                }
            }
        }
        nums.erase(nums.begin() + x);
        return nums;
    }
};