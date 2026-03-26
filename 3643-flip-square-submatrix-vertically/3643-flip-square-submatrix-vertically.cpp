class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> ans = grid;

        for (int i = 0; i < (k >> 1); i++) {
            for (int j = 0; j < k; j++) {
                swap(ans[x + i][y + j], ans[x + k - i - 1][y + j]);
            }
        }

        return ans;
    }
};