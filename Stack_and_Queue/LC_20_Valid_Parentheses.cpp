#include<stack>
class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        int s = str.size();
       for(int i=0;i<s;i++){
            if(str[i]==')'){
                if(i==0){return false;}
                else{
                    if(st.empty() || st.top()!='('){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
            }else if(str[i]=='}'){
                if(i==0){return false;}
                else{
                    if(st.empty() || st.top()!='{'){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
            }else if(str[i]==']'){
                if(i==0){return false;}
                else{
                    if(st.empty() || st.top()!='['){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
            }
            else{
                st.push(str[i]);
            }
            
        }
        return st.empty();
    }
};