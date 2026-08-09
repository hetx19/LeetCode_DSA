class Solution {
  private:
	int solve(vector<int>& prices, int index, int n, bool canBuy, vector<vector<int>>& dp) {
		if (index == n) {
			return 0;
		}
		
		if (dp[index][canBuy] != -1) {
			return dp[index][canBuy];
		}
		
		int profit = 0;
		
		if (canBuy) {
			profit = max(-prices[index] + solve(prices, index + 1, n, false, dp), solve(prices, index + 1, n, true, dp));
		} else {
			profit = max(prices[index] + solve(prices, index + 1, n, true, dp), solve(prices, index + 1, n, false, dp));
		}
		
		return dp[index][canBuy] = profit;
	}
	 
  public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, -1));
		
		return solve(prices, 0, n, true, dp);
	}
};