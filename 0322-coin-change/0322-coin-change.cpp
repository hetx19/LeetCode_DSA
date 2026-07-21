class Solution {
  public:
	int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		vector<int> prev(amount + 1, 0), current(amount + 1, 0);
		
		for (int t = 0; t <= amount; t++) {
			if (t % coins[0] == 0) {
				prev[t] = t / coins[0];
			} else {
				prev[t] = INT_MAX;
			}
		}
		
		for (int index = 1; index < n; index++) {
			for (int target = 0; target <= amount; target++) {
				int notTake = prev[target];
				
				int take = INT_MAX;
				if (coins[index] <= target) {
					take = current[target - coins[index]];
					if (take != INT_MAX) {
						take++;
					}
				}
				
				current[target] = min(take, notTake);
			}
			prev = current;
		}
		
		return (prev[amount] == INT_MAX) ? -1 : prev[amount];
	}
};