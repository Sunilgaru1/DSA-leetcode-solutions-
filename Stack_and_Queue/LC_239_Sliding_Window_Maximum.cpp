class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_sum;
        deque<int> Dq;
        for(int i=0 ;i<n;i++){

            if(!Dq.empty() && Dq.front()<=i-k){
                Dq.pop_front();
            }
            while(!Dq.empty() && nums[Dq.back()]<=nums[i]){
                Dq.pop_back();
            }
            Dq.push_back(i);

            if(i>=k-1){
                max_sum.push_back(nums[Dq.front()]);
            }
            
        }
        return max_sum;
    }
};