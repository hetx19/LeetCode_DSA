class Solution {
public:
    int overlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int width = max(0, min(ax2, bx2) - max(ax1, bx1));
        int height = max(0, min(ay2, by2) - max(ay1, by1));;

        return height * width;
    }

    int area(int ax1, int ax2, int ay1, int ay2) {
        return abs(ax1 - ax2) * abs(ay1 - ay2);
    }

public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        return area(ax1, ax2, ay1, ay2) + area(bx1, bx2, by1, by2) - overlapArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);      
    }
};