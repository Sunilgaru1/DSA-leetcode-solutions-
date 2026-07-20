class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k = k % (m*n);
        vector<vector<int>> ans(m, vector<int>(n));

        for(int row = 0; row < m; row++){
            for(int col = 0;col<n ; col++){
                int idx = row*n + col;
                int newIdx = (idx+k) % (m*n);

                int newRow = newIdx / n;
                int newCol = newIdx % n;

                ans[newRow][newCol] = grid[row][col];
            }
        }
        return ans;
    }
};