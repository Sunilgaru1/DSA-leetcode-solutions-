class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        vis[0] = true;
        int jump = 0;
        while(!q.empty()){
            int x = q.size();
            for(int i=0; i<x; i++){
                int j = q.front();
                q.pop();
                if(j == n-1) return jump;
                int next = j+1;
                int back = j-1;
                vector<int> val = mpp[arr[j]];

                if(next <= n-1 && !vis[next]){
                    q.push(next);
                    vis[next] = true;
                }
                if(back >= 0 && !vis[back]){
                    q.push(back);
                    vis[back] = true;
                }
                if(mpp.count(arr[j])){
                    for(int idx : mpp[arr[j]]){
                        if(!vis[idx]){
                            q.push(idx);
                            vis[idx] = true;
                        }
                    }
                    mpp.erase(arr[j]);
                }
            }
            jump ++;
        }
        return 0;
    }
};