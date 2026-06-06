class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            
            bool destroid = false;
            while(!st.empty() && st.top()>0 && asteroids[i]<0){

                if(st.top() < (-1*asteroids[i])){
                    st.pop();
                }
                else if(st.top()==(-1*asteroids[i])){
                    st.pop();
                    destroid = true;
                    break;
                }
                else{
                    destroid = true;
                    break;
                }
                
            }
            if(!destroid){
                st.push(asteroids[i]);
            }
        }
        vector<int> ans(st.size());
        for(int i= st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;    
    }
};