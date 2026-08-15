class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;
        bool add = false;
        for(int i=0; i<nums.size(); i++){
            xorr ^= nums[i];
            if(nums[i] != 0){
              add  = true;
            }
        }
        if(xorr !=0 ) return nums.size();
        if(add) return nums.size()-1;
        return 0;
    }
};