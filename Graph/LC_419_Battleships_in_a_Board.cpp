class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &board,int m,int n){
        board[i][j] = '.';
        int moveX[2] = {0,1};
        int moveY[2] = {1,0};
        for(int p=0;p<2;p++){
            int x = i + moveX[p];
            int y = j + moveY[p];
            if( x<m && y<n && board[x][y]=='X'){
                dfs(x,y,board,m,n);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int count = 0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    dfs(i,j,board,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};