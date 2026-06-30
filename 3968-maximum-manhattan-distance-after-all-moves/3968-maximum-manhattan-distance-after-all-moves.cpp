class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, count = 0;

        for (char ch : moves) {
            if (ch == 'U') {
                y++;
            } else if (ch == 'D') {
                y--;
            } else if (ch == 'R') {
                x++;
            } else if (ch == 'L') {
                x--;
            } else {
                count++;
            }
        }

        int ans = abs(x) + abs(y);

        return ans + count;
    }
};