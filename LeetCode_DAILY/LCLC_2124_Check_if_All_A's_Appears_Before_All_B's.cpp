class Solution {
public:
    bool checkString(string s) {
        int check = true;
        int before = 0;
        int total = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a'){
                if(check) before++;
                total++;
            }
            if(s[i]=='b'){
                check = false;
            }
        }
        return total==before;
    }
};