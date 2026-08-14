class Solution {
public:
    int moveX[4] = {1,0,-1,0};
    int moveY[4] = {0,1,0,-1};

    int dfs(int x, int y, int m, int n, vector<vector<int>>& board ,vector<vector<int>> &val){
        if(val[x][y]){
            return val[x][y];
        }
        int last = board[x][y];
        int mx = 1;
        for(int i = 0; i<4; i++){
            int dx = x + moveX[i];
            int dy = y + moveY[i];

            if(dx >= 0 && dy>=0 && dx<m && dy<n){
                if(board[dx][dy] > last){
                    mx = max(mx, 1+dfs(dx, dy, m, n, board , val));
                }
            }
        }
        return val[x][y] = mx;
    }
    int longestIncreasingPath(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int mx = 1;
        vector<vector<int>> val(m,vector<int>(n,0));
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                mx = max(dfs(i, j, m, n, board,val),mx);
            }
        }
        return mx;
    }
};