class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int need = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                if(r == 1){
                    ans++;
                    r = 0;
                }
                l++;
            }
            else{
                r++;
                if(r == 2){
                    if(l > 0){
                        l--;
                    }
                    else{
                        ans++;
                    }
                    r = 0;
                }
            }
        }

        return ans + 2*l + (r == 1 ? 1 : 0);
    }
};