class Solution {
public:
    long long sum = 0;
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return;
        sum += grid[i][j];
        grid[i][j] = 0;
        dfs(i+1,j,m,n,grid);
        dfs(i-1,j,m,n,grid);
        dfs(i,j+1,m,n,grid);
        dfs(i,j-1,m,n,grid);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    sum = 0;
                    dfs(i,j,m,n,grid);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};