class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> v;
        for(int num : nums){
            v.push_back(num*num);
        }
        sort(v.rbegin(), v.rend());
        int i = 0;
        int j = nums.size()-1;
        long long sum = 0;
        while(i<=j){
            sum += 1LL*v[i];
            if(i!=j) sum -= 1LL*v[j--];
            i++;
        }
        return sum;
    }
};