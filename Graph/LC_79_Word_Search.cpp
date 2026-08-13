class Solution {
public:
    int moveX[4] = {1,0,-1,0};
    int moveY[4] = {0,1,0,-1};

    bool dfs(int x, int y, vector<vector<char>>& board, string word, vector<vector<int>>& vis,int p){
        if(p==word.size()) return true;

        vis[x][y] = 1;

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<4; i++){
            int dx = x + moveX[i];
            int dy = y + moveY[i];

            if(dx >= 0 && dy>=0 && dx<m && dy<n && !vis[dx][dy]){
                if(board[dx][dy] == word[p]){
                    if(dfs(dx,dy,board,word,vis,p+1)){
                        return true;
                    }
                }
            }
        }
        vis[x][y] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,board,word,vis,1)){
                        return true;
                    }
                }

            }
        }
        return false;
    }
};