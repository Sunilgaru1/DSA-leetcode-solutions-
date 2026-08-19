class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int ,vector<int>> seats;
        for(auto &it : reservedSeats){
            int x = it[0];
            int y = it[1];
            seats[x].push_back(y);
        }
        int count = (n-seats.size())*2;
        for(auto &[r,seat] : seats){
            bool left = true;
            bool mid = true;
            bool right = true;

            for(int s: seat ){
                if(s>=2 && s<=5) left = false;
                if(s>=4 && s<=7) mid = false;
                if(s>=6 && s<=9) right = false;
            }

            if(left && right) count+=2;
            else if(left || right || mid) count ++;
        }
        return count;
    }
};