class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        long long max_area = 0;
        for(int i =0;i<=n;i++){
            int x = ((i==n)?0:heights[i]);

            while(!st.empty() && heights[st.top()]>x){
                int el = heights[st.top()];
                st.pop();
                int next_smaller = i;
                int prev_smaller = st.empty()?-1:st.top();
                long long width = (next_smaller - prev_smaller -1);
                max_area = max(max_area, 1LL *el* width);
            }
            st.push(i);
        }
        return max_area;
    }
};