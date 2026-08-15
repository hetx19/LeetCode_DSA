class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

        for (int index = n; index > 0; index--) {
            for (int prev_index = 0; prev_index <= index; prev_index++) {
                int len = dp[index + 1][prev_index];

                if (prev_index == 0 || nums[index - 1] > nums[prev_index - 1]) {
                    len = max(1 + dp[index + 1][index], len);
                }

                dp[index][prev_index] = len;
            }
        }

        return dp[1][0];
    }
};