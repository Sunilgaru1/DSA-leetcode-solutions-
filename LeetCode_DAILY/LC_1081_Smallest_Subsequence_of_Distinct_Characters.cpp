class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> chars(26,0);
        for(char ch:s){
            chars[ch-'a']++;
        }
        bool inAnswer[26] = {false};
        string ans = "";
        
        for(char ch:s){
            chars[ch-'a']--;
            if(inAnswer[ch-'a']) continue;

            while (!ans.empty()&& ans.back()>ch && chars[ans.back()-'a'] > 0){
                inAnswer[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans += ch;
            inAnswer[ch-'a'] = true;
        }
        return ans;
    }
};