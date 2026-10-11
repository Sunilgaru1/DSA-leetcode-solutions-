
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int curr = 0;
        int last = 0;

        for(int i = 0; i<n-1; i++){
            last = max(last, i+nums[i]);

            if(i == curr){
                jumps++;
                curr = last;
            }
        }

        return jumps;
    }
};
