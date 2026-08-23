class Solution {
public:
    bool sumGame(string num) {
        int c1 = 0, c2 = 0;
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<num.size()/2; i++){
            if(num[i]=='?') c1++;
            else sum1 += num[i]-'0';
        }
        for(int i=num.size()/2; i<num.size(); i++){
            if(num[i]=='?') c2++;
            else sum2 += num[i]-'0';
        }

        int cDiff = c1 - c2;
        int sDiff = sum1 - sum2;
 
        if(cDiff%2 == 0 && sDiff == 9*(c2-c1)/2){
            return false;
        }

        return true;
    }
};