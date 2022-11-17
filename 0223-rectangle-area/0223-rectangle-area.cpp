class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // if(ax1 > bx1)return computeArea(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2);
        int a1 = abs(ax2 - ax1)*abs(ay2 - ay1);
        int a2 = abs(bx2 - bx1)*abs(by2 - by1);
        
        int l = -(max(ax1,bx1) - min(ax2, bx2));
        int b = -(max(ay1, by1) - min(ay2, by2));
        if(l < 0 or b < 0) return a1 + a2;
        else return a1 + a2 - l * b;
    }
};