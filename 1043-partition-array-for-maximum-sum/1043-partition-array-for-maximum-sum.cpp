class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            int maxSum = INT_MIN, maxi = INT_MIN;
            int length = 0;

            for (int i = index; i < min(index + k, n); i++) {
                length++;
                maxi = max(maxi, arr[i]);

                int sum = (length * maxi) + dp[i + 1];

                maxSum = max(maxSum, sum);
            }

            dp[index] = maxSum;
        }

        return dp[0];
    }
};