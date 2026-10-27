class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m, string(n, '#'));
        int row = 0, col = 0;
        
        result[row][col] = '.';
        
        while (row < m - 1 || col < n - 1) {
            if (row < m - 1 && (col == n - 1 || abs((row + 1) * (n - 1) - col * (m - 1)) <= abs(row * (n - 1) - (col + 1) * (m - 1)))) {
                row++;
            } else {
                col++;
            }

            result[row][col] = '.';
        }
        
        return result;
    }
};