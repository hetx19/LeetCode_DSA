class Solution {
private:
    void dfs(int row, int column, vector<vector<int>>& ans, vector<vector<int>>& image, int initialColor, int newColor, int deltaRow[], int deltaCol[]) {
        ans[row][column] = newColor;
        int n = image.size(), m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + deltaRow[i];
            int ncol = column + deltaCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, initialColor, newColor, deltaRow, deltaCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};

        dfs(sr, sc, ans, image, initialColor, color, deltaRow, deltaCol);

        return ans;
    }
};