class Solution {
  private:
	int solve(vector<vector<int>>& grid, int row, int col1, int col2, int n, int m, vector<vector<vector<int>>>& dp) {
		if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) {
			return INT_MIN;
		}
		
		if (row == n - 1) {
			if (col1 == col2) {
				return dp[row][col1][col2] = grid[row][col1];
			}
			
			return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
		}

        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }
		
		int maxi = INT_MIN;
		vector<int> deltaCol = {-1, 0, +1};
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int value = 0;
				if (col1 == col2) {
					value = grid[row][col1];
				} else {
					value = grid[row][col1] + grid[row][col2];
				}
				
				int ncol1 = col1 + deltaCol[i];
				int ncol2 = col2 + deltaCol[j];
				value += solve(grid, row + 1, ncol1, ncol2, n, m, dp);
				
				maxi = max(maxi, value);
			}
		}
		
		return dp[row][col1][col2] = maxi;
	}
	
  public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m, -1)));

        return solve(grid, 0, 0, m - 1, n, m, dp);
    }
};