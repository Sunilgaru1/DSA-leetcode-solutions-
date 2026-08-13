class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long,int> mpp;
        if(n==1 && k==1) return 1;
        int max_count = 0;

        int i =0;
        int j =0;
        while(j<n && i<n){

            mpp[nums[j]]++;
            if(mpp[nums[j]] > k){
                while( i<n && mpp[nums[j]]>k){
                    mpp[nums[i]]--;
                    i++;
                }
            }
            max_count = max(max_count,j-i+1);
            j++;
        }
        return max_count;
    }
};