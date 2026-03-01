class Solution {
private:
    void bfs(int row, int col, vector<vector<bool>>& isVisted, vector<vector<char>>& grid) {
        isVisted[row][col] = true;
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();

            int dRow[4] = {-1, 0, 1, 0};
            int dCol[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !isVisted[nrow][ncol]) {
                        isVisted[nrow][ncol] = true;
                        q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        vector<vector<bool>> isVisted(m, vector<bool> (n, false));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!isVisted[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, isVisted, grid);
                }
            }
        }

        return count;
    }
};