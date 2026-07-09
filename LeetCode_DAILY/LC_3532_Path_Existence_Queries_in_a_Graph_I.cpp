class Solution {
public:
    vector<int> parent, rank_;

    int find(int x){
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y) return;

        if(rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;

        if(rank_[x] == rank_[y])
            rank_[x]++;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                        vector<vector<int>>& queries){

        parent.resize(n);
        rank_.assign(n,0);
        iota(parent.begin(),parent.end(), 0);

        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++)
            arr.push_back({nums[i],i});

        sort(arr.begin(),arr.end());

        for(int i = 1; i < n; i++){
            if(arr[i].first - arr[i-1].first <= maxDiff)
                unite(arr[i].second, arr[i-1].second);
        }

        vector<bool> ans;
        for(auto &q : queries)
            ans.push_back(find(q[0]) == find(q[1]));

        return ans;
    }
};
