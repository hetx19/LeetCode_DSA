class Solution {
  public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> current(2, vector<int>(3, 0)), next(2, vector<int>(3, 0));
		
		for (int index = n - 1; index >= 0; index--) {
			for (int canBuy = 0; canBuy < 2; canBuy++) {
				for (int cap = 1; cap < 3; cap++) {
					int profit = 0;
				
					if (canBuy) {
						profit = max(-prices[index] + next[0][cap], next[1][cap]);
					} else {
						profit = max(prices[index] + next[1][cap - 1], next[0][cap]);
					}
				
					current[canBuy][cap] = profit;
				}
			}
			next = current;
		}
		
		return current[true][2];
	}
};