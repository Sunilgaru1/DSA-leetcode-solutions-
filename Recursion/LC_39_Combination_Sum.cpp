class Solution {
public:
    void total_combination(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&temp,int i,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==candidates.size() || target<0){
            return;
        }

        temp.push_back(candidates[i]);
        total_combination(candidates,ans,temp,i,target-candidates[i]);

        temp.pop_back();
 
        total_combination(candidates,ans,temp,i+1,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        total_combination(candidates,ans,temp,0,target);
        return ans;
    }
};