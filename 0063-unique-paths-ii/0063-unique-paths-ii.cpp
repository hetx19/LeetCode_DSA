class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> current(n, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    current[j] = 0;
                } else if (i == 0 && j == 0) {
                    current[j] = (obstacleGrid[i][j]) ? 0 : 1;
                } else {
                    int up = 0, left = 0;

                    up = (i > 0) ? prev[j] : 0;
                    left = (j > 0) ? current[j - 1] : 0;

                    current[j] = up + left;
                }
            }

            prev = current;
        }

        return prev[n - 1];
    }
};