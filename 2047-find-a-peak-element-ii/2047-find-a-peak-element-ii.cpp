class Solution {
public:
    int maxElement(vector<vector<int>>& arr, int col) {
        int n = arr.size(), max_val = INT_MIN, index = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i][col] > max_val) {
                max_val = arr[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int low = 0, high = m - 1;

        // Binary search on column
        while(low <= high) {
            int mid = low + ((high - low) >> 1);

            // Find the index of the row with the maximum element in the middle column
            int row = maxElement(mat, mid);

            int left = mid - 1 >= 0 ? mat[row][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? mat[row][mid + 1] : INT_MIN;

            if(mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if(mat[row][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};