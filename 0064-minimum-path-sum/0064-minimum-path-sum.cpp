class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, -1);

        for (int i = 0; i < m; i++) {
            vector<int> current(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    current[j] = grid[i][j];
                } else {
                    int up = (i > 0) ? prev[j] : INT_MAX;
                    int left = (j > 0) ? current[j - 1] : INT_MAX;

                    current[j] = grid[i][j] + min(up, left);
                }
            }

            prev = current;
        }

        return prev[n - 1];
    }
};