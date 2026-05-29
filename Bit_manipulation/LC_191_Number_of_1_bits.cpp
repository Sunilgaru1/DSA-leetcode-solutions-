class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for(int i=0;i<31;i++){
            if(((n>>i) & 1 ) == 1){
                count++;
            }
            if(n>>i==0){
                break;
            }
        }
        return count;
    }
};