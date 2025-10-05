class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> transpose_matrix(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                transpose_matrix[i][j] = matrix[j][i];
            }
        }

        return transpose_matrix;
    }
};