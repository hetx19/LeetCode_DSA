class Solution {
private:
    int func(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j]) {
            return 0;
        }

        if (i == 0 && j == 0) {
            return dp[0][0];
        }

        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = func(obstacleGrid, i - 1, j, dp);
        int left = func(obstacleGrid, i, j - 1, dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        func(obstacleGrid, m - 1, n - 1, dp);

        return (obstacleGrid[m - 1][n - 1] == 0) ? dp[m - 1][n - 1] : 0;
    }
};