class Solution {
private:
    void RotateMatrix(vector<vector<int>> &mat) {
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i != j) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            RotateMatrix(mat);

            if (mat == target) {
                return true;
            }
        }

        return false;
    }
};