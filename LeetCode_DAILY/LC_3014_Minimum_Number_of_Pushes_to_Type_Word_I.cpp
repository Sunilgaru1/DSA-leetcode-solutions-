class Solution {
public:
    int minimumPushes(string word) {
        int push = 1;
        int total = 0;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(i==8 || i==16 || i==24){
                push++;
            } 
            total += push;
        }
        return total;
    }
};