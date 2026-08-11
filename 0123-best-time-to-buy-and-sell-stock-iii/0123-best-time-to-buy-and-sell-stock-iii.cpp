class Solution {
  public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int> (3, 0)));
		
		for (int index = n - 1; index >= 0; index--) {
			for (int canBuy = 0; canBuy < 2; canBuy++) {
				for (int cap = 1; cap < 3; cap++) {
					int profit = 0;
				
					if (canBuy) {
						profit = max(-prices[index] + dp[index + 1][0][cap], dp[index + 1][1][cap]);
					} else {
						profit = max(prices[index] + dp[index + 1][1][cap - 1], dp[index + 1][0][cap]);
					}
				
					dp[index][canBuy][cap] = profit;
				}
			}
		}
		
		return dp[0][true][2];
	}
};