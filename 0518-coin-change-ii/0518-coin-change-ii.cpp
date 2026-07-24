class Solution {
  public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
        vector<int> prev(amount + 1, 0), current(amount + 1, 0);
		
		for (int target = 0; target <= amount; target++) {
			prev[target] = (target % coins[0] == 0);
		}
		
		for (int index = 1; index < n; index++) {
			for (int target = 0; target <= amount; target++) {
				long long notTake = prev[target];
				long long take = (coins[index] <= target) ? current[target - coins[index]] : 0;
				
				current[target] = take + notTake;
			}
            prev = current;
		}
		
		return prev[amount];
	}
};