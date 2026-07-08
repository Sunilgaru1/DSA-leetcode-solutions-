class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid,int m,int n){
        grid[i][j] = '0';
        int moveX[4] = {0,1,0,-1};
        int moveY[4] = {1,0,-1,0};
        for(int p=0;p<4;p++){
            int x = i + moveX[p];
            int y = j + moveY[p];
            if( x>=0 && y>= 0 && x<m && y<n && grid[x][y]=='1'){
                dfs(x,y,grid,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};