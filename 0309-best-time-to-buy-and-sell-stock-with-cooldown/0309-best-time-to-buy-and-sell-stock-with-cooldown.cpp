class Solution {
private:
    int solve(vector<int>& prices, int n, int index, bool canBuy, vector<vector<int>>& dp) {
        if (index >= n) {
            return 0;
        }

        if (dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }

        int profit = 0;

        if (canBuy) {
            profit = max(-prices[index] + solve(prices, n, index + 1, false, dp), solve(prices, n, index + 1, true, dp));
        } else {
            profit = max(prices[index] + solve(prices, n, index + 2, true, dp), solve(prices, n, index + 1, false, dp));
        }

        return dp[index][canBuy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                int profit = 0;

                if (canBuy) {
                    profit = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
                } else {
                    profit = max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
                }

                dp[index][canBuy] = profit;
            }
        }

        return dp[0][1];
    }
};