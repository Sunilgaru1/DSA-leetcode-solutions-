class Solution {
public:
    int t[503][503];
    int score(int i,int j,vector<int> &piles){
        if(i>j) return 0;
        if(i==j) return piles[i];

        if(t[i][j] != (-1)) return t[i][j];
        int left = piles[i] + min(score(i+2,j,piles),score(i+1,j-1,piles));
        int right = piles[j] + min(score(i+1,j-1,piles),score(i,j-2,piles));
        return t[i][j] = max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int n = piles.size();

        int total_sum = 0;
        for(int i=0;i<n;i++){
            total_sum += piles[i];
        }
        int p1 = score(0,n-1,piles);
        int p2 = total_sum - p1;
        return p1>p2;
    }
};