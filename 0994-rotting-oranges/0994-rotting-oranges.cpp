class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visted(n, vector<bool> (m, false));

        int countFresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visted[i][j] = true;
                }

                if (grid[i][j] == 1) {
                    countFresh++;
                }
            }
        }

        int time = 0;
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            time = max(t, time);

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visted[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    visted[nrow][ncol] = true;
                    countFresh--;
                }
            }
        }

        if (countFresh > 0) {
            return -1;
        }

        return time;
    }
};