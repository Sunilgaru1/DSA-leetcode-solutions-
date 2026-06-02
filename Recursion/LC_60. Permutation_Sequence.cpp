class Solution {
public:
    int fact(int n){
        int ans = 1;
        for(int i=1;i<=n;i++){
            ans*=i;
        }
        return ans;
    }
    string permute(vector<int>& nums,string &ans,int n,int k){
        if(nums.empty()){
            return ans;
        }
        int f = fact(n-1);
        int index = (k)/f;
        ans += to_string(nums[index]);
        k = k%f;
        nums.erase(nums.begin()+index);
        return permute(nums,ans,n-1,k);
    }
    string getPermutation(int n, int k) {
        k--;
        vector<int> nums ;
        string ans = "";
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        return permute(nums,ans,n,k);
    }
};