class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> arr;
        int mn = 1e9;
        for(int i = nums.size()-1; i>=0; i--){
            mn = min(mn, nums[i]);
            arr.push_back(mn);
        }
        reverse(arr.begin(),arr.end());
        int mx = -1*1e9;
        for(int i=0; i<nums.size(); i++){
            mx = max(mx,nums[i]);
            if(mx-arr[i] <= k){
                return i;
            }
        }
        return -1;
    }
};