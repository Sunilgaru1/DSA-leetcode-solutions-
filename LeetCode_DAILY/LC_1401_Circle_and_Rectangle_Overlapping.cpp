class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int cx,cy;
        if(x1 > xCenter){
            cx = x1;
        }else if(x2 < xCenter){
            cx = x2;
        }
        else{
            cx = xCenter;
        }

        if(y1 > yCenter){
            cy = y1;
        }else if(y2 < yCenter){
            cy = y2;
        }
        else{
            cy = yCenter;
        }

        if(sqrt((cx-xCenter)*(cx-xCenter) + (cy-yCenter)*(cy-yCenter)) <= radius) return true;
        return false;
    }
};