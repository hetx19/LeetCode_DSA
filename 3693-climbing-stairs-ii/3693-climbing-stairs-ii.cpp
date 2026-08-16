class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            int cost = INT_MAX;

            for (int i = 0; i < 3; i++) {
                int next = index + i + 1;

                if (next <= n) {
                    cost = min(cost, dp[next] + costs[next - 1] + (i + 1) * (i + 1));
                }
            }

            dp[index] = cost;
        }

        return dp[0];
    }
};