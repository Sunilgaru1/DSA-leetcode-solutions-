class Solution {
public:
    bool ispalindrome(string s,int st,int end){
        while(st<=end){
            if(s[st++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void allpartitions(vector<vector<string>>&ans,vector<string>&temp,string s,int index){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i =index;i<s.size();i++){
            if(ispalindrome(s,index,i)){
                string part = s.substr(index,i-index+1);
                temp.push_back(part);
                allpartitions(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
       
        allpartitions(ans,temp,s,0);
        return ans;
    }
};