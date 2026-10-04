class Solution {
public:
    bool checkValidString(string s) {
        int r =0;
        int l =0;
        int ex =0;
        // if(s.size()==0) return false;
        // if(s.size()==1 && s[0] != '*') return false;
        for(char ch: s){
            if(ch=='('){
                r++;
            }
            else if(ch==')'){
                l++;
            }else{
                ex++;
            }
            if(l > r+ex){
                return false;
            }
        }
        l =0;
        r=0;
        ex =0;
        for(int i =s.size()-1; i>=0; i--){
            char ch = s[i];
            if(ch=='('){
                r++;
            }
            else if(ch==')'){
                l++;
            }else{
                ex++;
            }
            if(r > l+ex){
                return false;
            }
        }
        return true;
    }
};