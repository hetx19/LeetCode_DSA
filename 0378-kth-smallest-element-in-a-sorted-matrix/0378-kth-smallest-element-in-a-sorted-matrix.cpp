class Solution {
private:
    int counting(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;

        int row = 0, col = n - 1;

        while (row < n && col >= 0) {
            if (matrix[row][col] <= target) {
                count += (col + 1);
                row++;
            } else {
                col--;
            }
        }

        return count;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + ((high - low) / 2);

            int count = counting(matrix, mid);

            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};