class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int number = n ^ (n >> 1);
        return ((number & (number + 1)) == 0);
    }
};