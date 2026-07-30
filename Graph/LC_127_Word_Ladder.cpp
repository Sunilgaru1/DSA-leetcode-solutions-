class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            string word = node.first;
            int steps = node.second;

            if(word == endWord) return steps;
            for(int i=0;i<word.size();i++){
                char ori = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = ori;
            }
        }
        return 0;
    }
};