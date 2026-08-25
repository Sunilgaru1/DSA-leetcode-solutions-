class Solution {
public:
    int numSquares(int sum) {
        vector<int> nums;
        for(int i = 1; i*i <=sum; i++){
            nums.push_back(i*i);
        }
        int n = nums.size();
        vector<vector<int>> t(n+1,vector<int>(sum+1));
        t[0][0] = 0;

        for(int j = 1; j<=sum; j++){
            t[0][j] = 1e9;
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){

                int not_take = t[i-1][j];
                int take = 1e9;
                if(nums[i-1]<=j){
                    take = 1 + t[i][j-nums[i-1]];
                }
                t[i][j] = min(take,not_take);
            } 
        }
        return t[n][sum];
    }
};