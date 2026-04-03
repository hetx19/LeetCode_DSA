class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, -1, 0, +1};

        distance[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int difference = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1) {
                return difference;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), difference);
                    if (newEffort < distance[nrow][ncol]) {
                        distance[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;
    }
};