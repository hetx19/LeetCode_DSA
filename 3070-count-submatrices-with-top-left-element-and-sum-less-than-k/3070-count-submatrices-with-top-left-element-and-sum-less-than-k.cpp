class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = grid[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];

                if (dp[i + 1][j + 1] <= k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};