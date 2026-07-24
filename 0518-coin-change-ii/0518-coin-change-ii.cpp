class Solution {
  public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
		
		for (int target = 0; target <= amount; target++) {
			dp[0][target] = (target % coins[0] == 0);
		}
		
		for (int index = 1; index < n; index++) {
			for (int target = 0; target <= amount; target++) {
				long long notTake = dp[index - 1][target];
				long long take = 0;
                
                if (coins[index] <= target) {
                    take = dp[index][target - coins[index]];
                }
				
				dp[index][target] = take + notTake;
			}
		}
		
		return dp[n - 1][amount];
	}
};