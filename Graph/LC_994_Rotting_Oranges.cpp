class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m =grid[0].size();
        int fresh = 0;

        queue<pair<int,int>> q;
        int time = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = grid[i][j];
                if(val==2){
                    q.push({i,j});
                }
                if(val ==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return  0;
        while(!q.empty()){
            int size = q.size();
            bool infected = false;
            for(int s=0;s<size;s++){
                pair<int,int> temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                
                if(i>0 && grid[i-1][j]==1){
                    infected = true;
                    grid[i-1][j] = 2;
                    fresh--;
                    q.push({i-1,j});
                }
                if(i<n-1 && grid[i+1][j]==1){
                    infected = true;
                    grid[i+1][j] = 2;
                    fresh--;
                    q.push({i+1,j});
                }
                if(j>0 && grid[i][j-1]==1){
                    infected = true;
                    grid[i][j-1] = 2;
                    fresh--;
                    q.push({i,j-1});
                }
                if(j<m-1 &&grid[i][j+1]==1){
                    infected = true;
                    grid[i][j+1] = 2;
                    fresh--;
                    q.push({i,j+1});
                }
            }
            if(infected) time++;
        }
        if(fresh>0) return -1;
        return time;
    }
};