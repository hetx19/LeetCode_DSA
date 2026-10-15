class Solution {
private:
    long long nCr(int n, int r) {
        long long ans = 1;

        for (int i = 0; i < r; i++) {
            ans *= (n - i);
            ans /= (i + 1);
        }

        return ans;
    }

public:
    int numTrees(int n) {
        return (int)(nCr(2 * n, n) / (n + 1));
    }
};