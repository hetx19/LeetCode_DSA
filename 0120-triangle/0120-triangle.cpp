class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i].resize(i + 1, 0);
        }

        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }

        return dp[0][0];
    }
};