class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        int p = 1;
        while(n>=x){
            n -= x;
            x--;
            if(p==1) p = 2;
            else p = 1;
        }
        if(p==1) return false;
        return true;
    }
};