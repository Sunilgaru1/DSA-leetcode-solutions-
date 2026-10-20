class Solution {
public:
    bool isRotationPossible(vector<int> vec1, vector<int> vec2){
        vector<int> test = vec2;
        test.insert(end(test) , begin(vec2), end(vec2));
        return KMP(vec1, test);
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> srt = nums;
        sort(srt.begin(),srt.end());

        if(nums==srt) return 0;
        int ans = 0;
        for(int k =1; k<=n; k++){
            if(n%k != 0) continue;

            bool validK = true;
            for(int st =0; st<n; st+=k){
                vector<int> vec1(k);
                vector<int> vec2(k);
                for(int i = st; i<st+k; i++){
                    vec1.push_back(nums[i]);
                    vec2.push_back(srt[i]);
                }
                if(!isRotationPossible(vec1, vec2)){
                    validK = false;
                    break;
                }
            }
            if(validK){
                ans += k;
            }
        }
        return ans;
    }
};