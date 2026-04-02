class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;

        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));

        int deltaRow[] = {-1, -1, -1, 0, +1, +1, +1, 0};
        int deltaCol[] = {-1, 0, +1, +1, +1, 0, -1, -1}; 

        queue<pair<int, pair<int, int>>> q;
        distance[0][0] = 1;
        q.push({1, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && dis + 1 < distance[nrow][ncol]) {
                    if (nrow == n - 1 && ncol == n - 1) {
                        return dis + 1;
                    }
                    distance[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};