class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> arr(budget+1, 0);
        int mn = INT_MAX;
        for(auto& item : items){
            int f = item[0], price = item[1];
            mn = min(mn, price);
            int count = 0;
            for(auto& it : items) {
                if(it[0]%f == 0) {
                    count++;
                }
            }
            for(int j = budget; j>=price; j--){
                arr[j] = max(arr[j], arr[j-price] + count);
            }
        }
        int ans = 0;
        for(int j = 0; j<=budget; j++){
            ans = max(ans, arr[j] + (budget-j)/mn);
        }
        return ans;
    }
};