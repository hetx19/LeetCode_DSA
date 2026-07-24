class Solution {
  private:
	int solve(vector<int>& coins, int index, int amount, vector<vector<int>>& dp) {
		if (index == 0) {
			return dp[index][amount] = ((amount % coins[index] == 0) ? 1 : 0);
		}
		
		if (dp[index][amount] != -1) {
			return dp[index][amount];
		}
		
		int notTake = solve(coins, index - 1, amount, dp);
		int take = (coins[index] <= amount) ? solve(coins, index, amount - coins[index], dp) : 0;
		
		return dp[index][amount] = notTake + take;
	}
	
  public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
		
		return solve(coins, n - 1, amount, dp);
	}
};