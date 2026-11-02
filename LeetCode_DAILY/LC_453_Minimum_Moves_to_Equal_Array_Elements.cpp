class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int mn = INT_MAX;
        for(int x : nums){
            sum += x;
            mn = min(mn, x);
        }
        return sum-nums.size()*mn;
    }
};