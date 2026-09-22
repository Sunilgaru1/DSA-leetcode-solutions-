class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> arr(n+1, false);

        for(int num : nums){
            if(num>0&& num<=n){
                arr[num] = true;
            }
        }

        for(int i = 1; i<=n; i++){
            if(!arr[i]){
                return i;
            }
        }

        return n+1;
    }
};