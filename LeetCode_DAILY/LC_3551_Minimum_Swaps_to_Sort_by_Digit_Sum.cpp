class Solution {
public:
    int sum(int n){
        int s =0;
        while(n){
            s += n%10;
            n= n/10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            nums[i] = sum(nums[i]);
            mpp[nums[i]].push_back(x);
        }
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            nums[i] = mpp[x][0];
            mpp[x].erase(mpp[x].begin());
        }
        return nums;
    }
};