class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> result(n, vector<int>(n));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int newCol = (col - rowShift[row] % n + n) % n;
                int newRow = (row - colShift[newCol] % n + n) % n;
                result[newRow][newCol] = grid[row][col];
            }
        }

        return result;
    }
};