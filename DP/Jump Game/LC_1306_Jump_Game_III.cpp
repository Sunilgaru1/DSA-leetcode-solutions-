class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(arr[start]==0) return true;
        queue<int> q;

        q.push(start);
        vector<int> vis(n,0);
        vis[start] = 1;

        while(!q.empty()){
            int x = q.size();
            for(int i=0; i<x; i++){
                int j = q.front();
                q.pop();
                int next = j + arr[j];
                int back = j - arr[j];

                if(next <= n-1 && vis[next] != 1){
                    if(arr[next]==0) return true;
                    q.push(next);
                    vis[next] = 1;
                }
                if(back >= 0 && vis[back] != 1){
                    if(arr[back]==0) return true;
                    q.push(back);
                    vis[back] = 1;
                }
            }
        }
        return false;
    }
};