class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for(int i=0; i<arr1.size(); i++){
            int x = arr1[i];
            bool ans = true;
            for(int j=0; j<arr2.size(); j++){
                int y = abs(x-arr2[j]);
                if(y<=d){
                    ans = false;
                    break;
                }
            }
            if(ans){
                count++;
            }
        }
        return count;
    }
};