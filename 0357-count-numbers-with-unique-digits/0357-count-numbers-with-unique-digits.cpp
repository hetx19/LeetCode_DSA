class Solution {
private:
    int computerCermutaion(int n, int r) {
        int ans = 1;
        for (int i = 0; i < r; i++) {
            ans *= (n - i);
        }

        return ans;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            dp[i + 1] += dp[i] + 9 * computerCermutaion(9, i);
        }

        return dp[n];
    }
};