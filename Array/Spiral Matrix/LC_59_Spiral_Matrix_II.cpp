class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        vector<vector<int>> ans(n,vector<int>(n));
        int i = 0,j =0;
        int count = n*n;
        int r = 1;
        int p = 1;
        while(count>0){
            while(j < n-r+1 && count > 0){
                ans[i][j] = p;
                p++;
                j++;
                count--;
            }
            j--;
            i++;
            while(i < m-r+1 && count > 0){
                ans[i][j] = p;
                p++;
                i++;
                count--;
            }
            i--;
            j--;
            while(j >= r-1 && count > 0){
                ans[i][j] = p;
                p++;
                j--;
                count--;
            }
            j++;
            i--;
            while(i >= r && count > 0){
                ans[i][j] = p;
                p++;
                i--;
                count--;
            }
            i++;
            j++;
            r++;
        }
        return ans;
    }
};