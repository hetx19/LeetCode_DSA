class Solution {
private:
    int solve(vector<int>& costs, int n, int index, vector<int>& dp) {
        if (index == n) {
            return dp[index] = 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int cost = INT_MAX;

        for (int i = 0; i < 3; i++) {
            int next = index + i + 1;

            if (next <= n) {
                cost = min(cost, solve(costs, n, next, dp) + costs[next - 1] + (i + 1) * (i + 1));
            }
        }

        return dp[index] = cost;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return solve(costs, n, 0, dp);
    }
};