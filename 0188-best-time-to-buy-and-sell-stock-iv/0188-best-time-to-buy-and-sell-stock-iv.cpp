class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxTransaction = 2 * k;

        vector<vector<int>> dp(n + 1, vector<int>(maxTransaction + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int transactionNo = 0; transactionNo < maxTransaction; transactionNo++) {
                int profit = 0;

                if (transactionNo & 1) {
                    profit = max(prices[index] + dp[index + 1][transactionNo + 1], dp[index + 1][transactionNo]);
                } else {
                    profit = max(-prices[index] + dp[index + 1][transactionNo + 1], dp[index + 1][transactionNo]);
                }

                dp[index][transactionNo] = profit;
            }
        }

        return dp[0][0];
    }
};