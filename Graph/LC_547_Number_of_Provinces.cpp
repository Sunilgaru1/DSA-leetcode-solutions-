class Solution {
public:
    void dfs(vector<vector<int>> &isConnected,int n,vector<int> &visited){
        visited[n] = 1;
        for(int j=0;j<isConnected[n].size();j++){
            if( isConnected[n][j] && !visited[j]){
                dfs(isConnected,j,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n+1);
        int count = 0;
        for(int i =0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};