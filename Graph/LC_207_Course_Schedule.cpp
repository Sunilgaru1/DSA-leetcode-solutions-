class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses, 0);

        for(auto &p : prerequisites){
            int course = p[0];
            int pre = p[1];

            adj[pre].push_back(course);
            in_degree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            count++;
            for(int it : adj[num]){
                in_degree[it]--;
                if(in_degree[it]==0){
                    q.push(it);
                }
            }
        }
        return numCourses == count;
    }
};