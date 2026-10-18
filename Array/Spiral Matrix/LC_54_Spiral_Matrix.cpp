class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i=0 , j=0;
        int n = matrix[0].size();
        int m = matrix.size();
        int r = 1;
        int count = n*m;
        while(count>0){

            while(i<=n-r && count>0){
                ans.push_back(matrix[j][i]);
                i++;
                count--;
            }
            i--;
            j++;
            while(j<=m-r && count>0){
                ans.push_back(matrix[j][i]);
                j++;
                count--;
            }
            j--;
            i--;
            while(i>=r-1 && count>0){
                ans.push_back(matrix[j][i]);
                i--;
                count--;
            }
            i++;
            j--;
            while(j>=r && count>0){
                ans.push_back(matrix[j][i]);
                j--;
                count--;
            }
            i++;
            j++;
            r++;
        }
        return ans;
    }
};