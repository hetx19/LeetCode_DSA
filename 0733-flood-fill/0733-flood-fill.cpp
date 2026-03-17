class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();

        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            ans[row][col] = color;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == initialColor && ans[nrow][ncol] != color) {
                    q.push({nrow, ncol});
                }
            }
        }

        return ans;
    }
};