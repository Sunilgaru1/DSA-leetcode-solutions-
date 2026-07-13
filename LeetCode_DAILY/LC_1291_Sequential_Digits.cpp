class Solution {
public:
    int get_first(int low,int &n){
        int x;
        while(low){
            x = low;
            low /= 10;
            n++;
        }
        return x;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int n = 0;
        get_first(low,n);
        while(n<=9){
            for (int first = 1; first+n-1<=9; first++){
                long long temp = 0;
                for(int i=0;i<n;i++){
                    temp = temp*10 + (first+i);
                }
                if(temp>=low && temp<=high) ans.push_back(temp);
            }
            n++;
        }
        return ans;
    }
};