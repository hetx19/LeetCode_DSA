class Solution {
  public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int> (m, 0)));
        
        for (int col1 = 0; col1 < m; col1++) {
	        for (int col2 = 0; col2 < m; col2++) {
		        if (col1 == col2) {
			        dp[n - 1][col1][col2] = grid[n - 1][col1];
		        } else {
			        dp[n - 1][col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];
		        }
	        }
        }
        
        for (int i = n - 2; i >= 0; i--) {
	        for (int col1 = 0; col1 < m; col1++) {
		        for (int col2 = 0; col2 < m; col2++) {
			        int maxi = INT_MIN;
			        vector<int> deltaCol = {-1, 0, +1};
			        
					for (int x = 0; x < 3; x++) {
						for (int y = 0; y < 3; y++) {
							int value = 0;
							if (col1 == col2) {
								value = grid[i][col1];
							} else {
								value = grid[i][col1] + grid[i][col2];
							}
				
							int ncol1 = col1 + deltaCol[x];
							int ncol2 = col2 + deltaCol[y];
							
							if (ncol1 >= 0 && ncol1 < m && ncol2 >= 0 && ncol2 < m) {
								value += dp[i + 1][ncol1][ncol2];
							} else {
								value += INT_MIN;
							}
							
							maxi = max(maxi, value);
						}
					}
					
					dp[i][col1][col2] = maxi;
		        }
	        }
        }
        
        return dp[0][0][m - 1];
    }
};