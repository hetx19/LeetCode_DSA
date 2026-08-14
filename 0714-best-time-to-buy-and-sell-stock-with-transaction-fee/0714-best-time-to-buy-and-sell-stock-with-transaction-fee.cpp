class Solution {
  public:
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		vector<int> current(2, 0), next(2, 0);
		
		for (int index = n - 1; index >= 0; index--) {
			for (int canBuy = 0; canBuy < 2; canBuy++) {
				int profit = 0;
				
				if (canBuy) {
					profit = max(-prices[index] + next[0], next[1]);
				} else {
					profit = max(prices[index] - fee + next[1], next[0]);
				}
				
				current[canBuy] = profit;
			}
			next = current;
		}
		
		return current[1];
	}
};