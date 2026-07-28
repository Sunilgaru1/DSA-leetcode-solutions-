class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count_char(26,0);
        for(char &ch :s){
            count_char[ch-'a']++;
        }
        string left = "";
        string mid = "";
        for(int i = 0; i<26; i++){
            left.append(count_char[i]/2, char('a'+i));

            if(count_char[i]%2) mid = char('a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};