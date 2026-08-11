class Solution {
  private:
	int solve(vector<int>& prices, int n, int index, bool canBuy, int cap, vector<vector<vector<int>>>& dp) {
		if (index == n) {
			return 0;
		}
		
		if (cap == 0) {
			return dp[index][canBuy][cap] = 0;
		}
		
		if (dp[index][canBuy][cap] != -1) {
			return dp[index][canBuy][cap];
		}
		
		int profit = 0;
		
		if (canBuy) {
			profit = max(-prices[index] + solve(prices, n, index + 1, false, cap, dp), solve(prices, n, index + 1, true, cap, dp));
		} else {
			profit = max(prices[index] + solve(prices, n, index + 1, true, cap - 1, dp), solve(prices, n, index + 1, false, cap, dp));
		}
		
		return dp[index][canBuy][cap] = profit;
	}
	
  public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
		
		return solve(prices, n, 0, true, 2, dp);
	}
};