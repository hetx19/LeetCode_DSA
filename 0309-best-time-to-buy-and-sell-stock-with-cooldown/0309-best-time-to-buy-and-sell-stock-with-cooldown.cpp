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
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, n, 0, true, dp);
    }
};