class Solution {
private:
    int solve(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int maxCoins = INT_MIN;

        for (int index = start; index <= end; index++) {
            int coins = nums[start - 1] * nums[index] * nums[end + 1] + solve(nums, start, index - 1, dp) + solve(nums, index + 1, end, dp);

            maxCoins = max(maxCoins, coins);
        }

        return dp[start][end] = maxCoins;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(nums, 1, n, dp);
    }
};