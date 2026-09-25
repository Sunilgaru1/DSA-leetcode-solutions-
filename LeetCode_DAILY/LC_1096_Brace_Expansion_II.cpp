class Solution {
public:
    int idx = 0;
    string s;
    int n;
    set<string> getUnit(){
        set<string> result;

        if(s[idx]=='{'){
            idx++;
            result = getUnion();
            idx++;   
        }
        else{
            result = {string(1,s[idx])};
            idx++;
        }
        return result;
    }
    set<string> getCon(){
        set<string> result = {""};
        while(idx <n && (s[idx] == '{' || isalpha(s[idx]))){
            set<string> temp = getUnit();

            set<string> CR;
            for(const string& left : result){
                for(const string& right: temp){
                    CR.insert(left+right);
                }
            }
            result = CR;
        }
        return result;
    }
    set<string> getUnion(){
        set<string> result;
        while(true){
            set<string> temp = getCon();
            result.insert(begin(temp),end(temp));
            if(idx <n && s[idx]==',') idx++;
            else break;
        }
        return result;
    }
    vector<string> braceExpansionII(string exp) {
        n = exp.size();
        s = exp;
        idx = 0;
        set<string> st = getUnion();
        vector<string> result(begin(st),end(st));
        return result;
    }
};