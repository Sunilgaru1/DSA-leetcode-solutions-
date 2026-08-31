class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<long long>> t(target + 1, vector<long long>(n,0));

        for(int j = 1; j<=target; j++){
            for(int i = 0; i < n; i++){
                if(nums[i] > j) continue;
                
                if(nums[i] == j){
                    t[j][i] = 1;
                }
                
                if(nums[i] < j){
                    for(int k = 0; k<n; k++){
                        if(t[j][i] <= INT_MAX - t[j-nums[i]][k]){
                            t[j][i] += t[j - nums[i]][k];
                        }
                    }
                }
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if (ans <= INT_MAX - t[target][i]) {
                ans += t[target][i];
            }
        }

        return (int)ans;
    }
};