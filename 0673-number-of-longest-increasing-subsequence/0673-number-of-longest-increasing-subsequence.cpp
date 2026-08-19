class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int maxLength = 1;

        for (int index = 0; index < n; index++) {
            for (int prev = 0; prev < index; prev++) {
                if (nums[index] > nums[prev] && dp[index] < 1 + dp[prev]) {
                    dp[index] = 1 + dp[prev];
                    count[index] = count[prev];
                } else if (nums[index] > nums[prev] && dp[index] == 1 + dp[prev]) {
                    count[index] += count[prev];
                }
            }
            maxLength = max(maxLength, dp[index]);
        }

        int cnt = 0;
        for (int index = 0; index < n; index++) {
            if (dp[index] == maxLength) {
                cnt += count[index];
            }
        }

        return cnt;
    }
};