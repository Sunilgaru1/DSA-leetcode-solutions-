class Solution {
public:
    void allstrings(vector<string> &ans,unordered_map<int,string> &mpp,string temp ,string digits,int p){
        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<mpp[digits[p]-'0'].size();i++){
            temp += mpp[digits[p]-'0'][i];
            allstrings(ans,mpp,temp,digits,p+1);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mpp = {
            {2 , "abc"}, {3 , "def"},
            {4 , "ghi"}, {5 , "jkl"},
            {6 , "mno"}, {7 , "pqrs"},
            {8 , "tuv"}, {9 , "wxyz"}
        };
        vector<string> ans;
        string temp = "";
        if(digits.empty()){
        return {};
        }
        allstrings(ans,mpp,temp,digits,0);
        return ans;
    }
};