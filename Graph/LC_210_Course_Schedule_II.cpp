class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses,0);
        for(auto it:prerequisites){
            int course = it[0];
            int pre = it[1];

            adj[pre].push_back(course);
            in_degree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            ans.push_back(num);
            for(int i: adj[num]){
                in_degree[i]--;
                if(in_degree[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size() == numCourses)  return ans;
        
        return {};
    }
};