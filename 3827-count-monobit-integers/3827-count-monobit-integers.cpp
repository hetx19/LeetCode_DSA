class Solution {
public:
    int countMonobit(int n) {
        return log2(n + 1) + 1;
    }
};