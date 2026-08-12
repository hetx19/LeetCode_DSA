class Solution {
private:
    int solve(vector<int>& prices, int n, int index, int transactionNo, int k, vector<vector<int>>& dp) {
        if (index == n || transactionNo == k) {
            return 0;
        }

        if (dp[index][transactionNo] != -1) {
            return dp[index][transactionNo];
        }

        int profit = 0;

        if (transactionNo & 1) {
            profit = max(prices[index] + solve(prices, n, index + 1, transactionNo + 1, k, dp), solve(prices, n, index + 1, transactionNo, k, dp));
        } else {
            profit = max(-prices[index] + solve(prices, n, index + 1, transactionNo + 1, k, dp), solve(prices, n, index + 1, transactionNo, k, dp));
        }

        return dp[index][transactionNo] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxTransaction = 2 * k;

        vector<vector<int>> dp(n, vector<int>(maxTransaction, -1));

        return solve(prices, n, 0, 0, maxTransaction, dp);
    }
};