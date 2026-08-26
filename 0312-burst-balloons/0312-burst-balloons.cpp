class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int start = n; start > 0; start--) {
            for (int end = 1; end <= n; end++) {
                if (start > end) {
                    continue;
                }

                int maxCoins = INT_MIN;
                
                for (int index = start; index <= end; index++) {
                    int coins = nums[start - 1] * nums[index] * nums[end + 1] + dp[start][index - 1] + dp[index + 1][end];

                    maxCoins = max(maxCoins, coins);
                }
                
                dp[start][end] = maxCoins;
            }
        }

        return dp[1][n];
    }
};