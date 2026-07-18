class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> freq(mx+1,0);
        for(int i=0;i<n;i++){
            int num = nums[i];

            for(int j=1;j*j<=num;j++){
                if(num%j==0){
                    freq[j]++;
                    if(num/j!=j) freq[num/j]++;
                }
            }
        }
        vector<long long> pairs(mx+1, 0);
        for(int i = 1;i<=mx; i++){
            pairs[i] = 1LL*freq[i]*(freq[i]-1)/2;
        }
        for(int i=mx;i>0;i--){
            int indx = i;
            for(int j = 2;j*indx <= mx;j++){
                pairs[i] -= pairs[indx*j];
            }
        }
        long long sum = 0;
        vector<long long> prefix(mx+1,0);
        for(int i=1;i<=mx;i++){
            sum += pairs[i];
            prefix[i] = sum;
        }

        vector<int> ans;
        for(int q = 0;q<queries.size();q++){
            auto it = upper_bound(prefix.begin(),prefix.end(),queries[q]);
            ans.push_back(distance(prefix.begin(),it));
        }
        return ans;
    }
};