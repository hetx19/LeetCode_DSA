class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int maxTransaction = 2 * k;

        vector<int> current(maxTransaction + 1, 0), next(maxTransaction + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int transactionNo = 0; transactionNo < maxTransaction; transactionNo++) {
                int profit = 0;

                if (transactionNo & 1) {
                    profit = max(prices[index] + next[transactionNo + 1], next[transactionNo]);
                } else {
                    profit = max(-prices[index] + next[transactionNo + 1], next[transactionNo]);
                }

                current[transactionNo] = profit;
            }
            next = current;
        }

        return current[0];
    }
};