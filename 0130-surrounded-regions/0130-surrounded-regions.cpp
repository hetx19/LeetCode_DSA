class Solution {
private:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, int deltaRow[], int deltaCol[]) {
        visited[row][col] = true;

        int m = board.size(), n = board[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(board, visited, nrow, ncol, deltaRow, deltaCol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, -1, 0, +1};

        for (int j = 0; j < n; j++) {
            if (!visited[0][j] && board[0][j] == 'O') {
                dfs(board, visited, 0, j, deltaRow, deltaCol);
            }
            if (!visited[m - 1][j] && board[m - 1][j] == 'O') {
                dfs(board, visited, m - 1, j, deltaRow, deltaCol);
            }
        }

        for (int i = 0; i < m; i++) {
            if (!visited[i][0] && board[i][0] == 'O') {
                dfs(board, visited, i, 0, deltaRow, deltaCol);
            }
            if (!visited[i][n - 1] && board[i][n - 1] == 'O') {
                dfs(board, visited, i, n - 1, deltaRow, deltaCol);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};