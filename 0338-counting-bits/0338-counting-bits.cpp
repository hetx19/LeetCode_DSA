class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);

        for (int num = 1; num <= n; num++) {
            dp[num] = dp[num >> 1] + (num & 1);
        }

        return dp;
    }
};