class Solution {
  private:
    int maxElement(vector<vector<int>>& mat, int col) {
		int m = mat.size(), maxValue = INT_MIN, index = -1;
		
		for (int i = 0; i < m; i++) {
			if (mat[i][col] > maxValue) {
				maxValue = mat[i][col];
				index = i;
			}
		}
		
		return index;
	}
	
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat[0].size();
        int low = 0, high = n - 1;
    
        while (low <= high) {
            int mid = low + ((high - low) / 2);

        
            int row = maxElement(mat, mid);
            int left = (mid > 0) ? mat[row][mid - 1] : INT_MIN;
            int right = (mid + 1 < n) ? mat[row][mid + 1] : INT_MIN;

            if (mat[row][mid] >= left &&  mat[row][mid] >= right) {
                return {row, mid};
            } else if (right > mat[row][mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};