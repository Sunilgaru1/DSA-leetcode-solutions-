class Solution {
public:
    vector<int> prevMin(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;

        for(int i =0;i<arr.size();i++){

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nextMin(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        int n = arr.size();
        for(int i =n-1;i>=0;i--){

            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = arr.size();
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> prevMini = prevMin(arr);
        vector<int> nextMini = nextMin(arr);
        int mod = 1e9 + 7;
        int sum = 0;

        for(int i = 0;i<arr.size();i++){
            
            int left = i-prevMini[i];
            int right = nextMini[i]-i;

            long long total_subarr = left*right*1LL;

            int val = (total_subarr*arr[i]*1LL)%mod;

            sum = (sum+val)%mod;

        }
        return sum;
    }
};