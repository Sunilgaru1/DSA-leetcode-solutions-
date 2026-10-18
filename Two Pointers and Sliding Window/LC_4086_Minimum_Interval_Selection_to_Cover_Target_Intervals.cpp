class Solution {
public:
    int solve(vector<vector<int>> &arr, vector<vector<int>>& aI){
        int n = aI.size();
        int ans = 0;
        int i = 0;
        int last =0;

        for(int j =0; j<arr.size(); j++){
            int st = arr[j][0];
            int end = arr[j][1];

            while(last < end){
                int curr = max(st,last);
                int best = last;

                while(i<n && aI[i][0]<=curr){
                    best = max(best,aI[i][1]);
                    i++;
                }
                if(best<curr) return -1;
                if(best==curr && curr<end) return -1;
                last = best;
                ans++;
            }
        }
        return ans;
    }
    int minSelection(vector<vector<int>>& aI, vector<vector<int>>& tI) {
        vector<vector<int>> arr;
        sort(tI.begin(),tI.end());
        sort(aI.begin(),aI.end());
        int st = tI[0][0];
        int end = tI[0][1];
        for(int i=1; i<tI.size(); i++){
            if(end < tI[i][0]){
                arr.push_back({st,end});
                st = tI[i][0];
                end = tI[i][1];
            }else{
                if(end<tI[i][1]) end = tI[i][1];
            }
        }
        arr.push_back({st,end});
        return solve(arr,aI);
    }
};