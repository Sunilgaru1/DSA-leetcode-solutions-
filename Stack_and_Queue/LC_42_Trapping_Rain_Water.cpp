class Solution {
public:
    vector<int> prevMax(vector<int>& arr){
        stack<int> st;
        vector<int> ans(arr.size());

        for(int i =0;i<arr.size();i++){
        
            if(st.empty() || st.top()<=arr[i]){
                st.push(arr[i]);
            }
            ans[i] = st.top();
        }
        return ans;
    }
    vector<int> nextMax(vector<int>& arr){
        stack<int> st;
        vector<int> ans(arr.size());

        for(int i =arr.size()-1;i>=0;i--){

            if(st.empty() || st.top()<=arr[i]){
                st.push(arr[i]);
            }
            ans[i] = st.top();
        }
        return ans;

    }
    int trap(vector<int>& height) {
        vector<int> prevMaxi = prevMax(height);
        vector<int> nextMaxi = nextMax(height);

        int n = height.size();
        int sum = 0;

        for(int i=0;i<n;i++){

            int x = min(prevMaxi[i],nextMaxi[i]);
            sum+= (x-height[i]);
        }
        return sum;
    }
};