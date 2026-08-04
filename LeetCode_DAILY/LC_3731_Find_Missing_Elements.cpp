class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int x = nums[0];
        int i = 0;
        while(i<nums.size()){
            if(nums[i]!=x){
                ans.push_back(x);
            }else i++;
            x++;
        }
        return ans;
    }
};