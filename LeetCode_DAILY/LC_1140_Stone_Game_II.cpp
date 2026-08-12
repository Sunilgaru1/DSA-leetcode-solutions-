class Solution {
public:
    int t[2][101][101];
    int score(int person ,int i,int M,vector<int> &piles){
        if(i>=piles.size()) return 0;
        if(t[person][i][M] != (-1)) return t[person][i][M];
        int taken = (person==1)?(-1):INT_MAX;
        int stones = 0;
        for(int X = 1; X <= min(2*M,(int)piles.size()-i) ; X++){
            stones += piles[i+X-1];
            if(person==1){
                taken = max(taken ,stones + score(0,i+X,max(M,X),piles));
            }else {
                taken = min(taken,score(1,i+X,max(M,X),piles));
            }
        }
        return t[person][i][M] = taken;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        return score(1,0,1,piles);
    }
};