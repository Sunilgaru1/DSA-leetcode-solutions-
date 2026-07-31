class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26,0);
        for(int i=0;i<word.size();i++){
            count[word[i]-'a']++;
        }
        sort(count.rbegin(),count.rend());
        int total = 0;
        int push = 1;
        for(int i=0;i<26;i++){
            total += count[i]*((i/8)+1);
        }
        return total;
    }
};