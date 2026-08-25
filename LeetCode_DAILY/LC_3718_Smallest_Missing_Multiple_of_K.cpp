class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int count = 1;
        while(i<nums.size()){
            if(nums[i] == count*k){
                count++;
            }
            else if(nums[i] > count*k){
                return count*k;
            }
            i++;
        }
        return count*k;
    }
};