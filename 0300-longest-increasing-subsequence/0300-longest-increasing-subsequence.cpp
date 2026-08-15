class Solution {
private:
    int solve(vector<int>& nums, int n, int index, int prev_index, vector<vector<int>>& dp) {
        if (index > n) {
            return 0;
        }

        if (dp[index][prev_index] != -1) {
            return dp[index][prev_index];
        }

        int len = solve(nums, n, index + 1, prev_index, dp);
        if (prev_index == 0 || nums[index - 1] > nums[prev_index - 1]) {
            len = max(1 + solve(nums, n, index + 1, index, dp), len);
        }

        return dp[index][prev_index] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(nums, n, 1, 0, dp);
    }
};