class Solution {
public:
    vector<int> prevMin(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;

        for(int i =0;i<arr.size();i++){

            while(!st.empty() && arr[st.top()]>arr[i]){
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

            while(!st.empty() && arr[st.top()]>=arr[i]){
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
    vector<int> prevMax(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;

        for(int i =0;i<arr.size();i++){

            while(!st.empty() && arr[st.top()]<arr[i]){
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

    vector<int> nextMax(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        int n = arr.size();
        for(int i =n-1;i>=0;i--){

            while(!st.empty() && arr[st.top()]<=arr[i]){
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
    long long subArrayRanges(vector<int>& arr) {
        vector<int> prevMini = prevMin(arr);
        vector<int> nextMini = nextMin(arr);
        vector<int> prevMaxi = prevMax(arr);
        vector<int> nextMaxi = nextMax(arr);

        long long sum_max = 0;
        long long sum_min = 0;

        for(int i = 0;i<arr.size();i++){
            
            long long left_min = i-prevMini[i];
            long long right_min = nextMini[i]-i;

            long long total_subarr_min = left_min*right_min*1LL;

            long long val_min = (total_subarr_min*arr[i]*1LL);

            sum_min = (sum_min + val_min);

            long long left_max = i-prevMaxi[i];
            long long right_max = nextMaxi[i]-i;

            long long total_subarr_max = left_max*right_max*1LL;

            long long val_max = (total_subarr_max*arr[i]*1LL);

            sum_max = (sum_max + val_max);

        }
        return (sum_max - sum_min);
    }
};