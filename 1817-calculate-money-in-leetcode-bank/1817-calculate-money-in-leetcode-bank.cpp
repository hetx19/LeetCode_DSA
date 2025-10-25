class Solution {
public:
    int totalMoney(int n) {
        int monday = 1;
        int total = 0;

        while(n > 0) {
            for(int i = 0; i < min(n, 7); i++) {
                total += monday + i;
            }

            n -= 7;
            monday++;
        }

        return total;
    }
};