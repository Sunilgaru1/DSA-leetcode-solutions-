class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n = num.size();
        for(int i = 0;i<n;i++){

            while(!st.empty() &&  k>0 &&  st.top()>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans+= char(st.top()+'0');
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        while(!ans.empty() && ans[0] == '0'){
            ans.erase(0,1);
        }

        if(ans.empty()){
            return "0";
        }
        
        return ans;
    }
};