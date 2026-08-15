class Solution {
private:
    void solve(int n, int col,vector<bool>& leftRow, vector<bool>& upperDiagonal, vector<bool>& lowerDiagonal, vector<string>& board, vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (!leftRow[row] && !upperDiagonal[n - 1 + col - row] && !lowerDiagonal[row + col]) {
                board[row][col] = 'Q';
                leftRow[row] = true;
                upperDiagonal[n - 1 + col - row] = true;
                lowerDiagonal[row + col] = true;

                solve(n, col + 1, leftRow, upperDiagonal, lowerDiagonal, board, ans);

                board[row][col] = '.';
                leftRow[row] = false;
                upperDiagonal[n - 1 + col - row] = false;
                lowerDiagonal[row + col] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<bool> leftRow(n, false), upperDiagonal(2 * n - 1, false), lowerDiagonal(2 * n - 1, false);

        solve(n, 0, leftRow, upperDiagonal, lowerDiagonal, board, ans);

        return ans;
    }
};