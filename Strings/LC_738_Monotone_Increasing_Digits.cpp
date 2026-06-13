class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int x = num.size();
        if(x==1) return n;
        int i = x-1;
        while(i>0){
            if(num[i]<num[i-1]){
                num[i-1]--;
                x = i;
            }
            i--;
        }
        while(x<num.size()){
            num[x] = '9';
            x++;
        } 
        return stoi(num);
    }
};