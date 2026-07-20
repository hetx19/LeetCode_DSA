class Solution {
  private:
    void shift(vector<vector<int>>& grid, int i, int j, int col) {
        while (i < j) {
            swap(grid[i / col][i % col], grid[j / col][j % col]);
            i++;
            j--;
        }
    }

  public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (k == 0) {
            return grid;
        }
        int row = grid.size(), col = grid[0].size();
        int n = row * col;

        k = k % n;

        shift(grid, 0, n - 1, col);
        shift(grid, 0, k - 1, col);
        shift(grid, k, n - 1, col);

        return grid;
    }
};