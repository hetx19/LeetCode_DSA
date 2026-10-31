class Solution {
private:
    int numberOfSetBits(int n) {
        int counter = 0;

        while (n > 0) {
            counter++;
            n = n & (n - 1);
        }

        return counter;
    }

public:
    int calculateScore(int a, int b) {
        int s1 = numberOfSetBits(a), s2 = numberOfSetBits(b);

        return (s1 >= s2) ? s1 * s2 : s2 / s1;
    }
};