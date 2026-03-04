class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int m = mat.size(), n = mat[0].size();

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }

                bool isOK = true;
                for (int i = 0; i < m; i++) {
                    if (i != row && mat[i][col] == 1) {
                        isOK = false;
                        break;
                    }
                }

                for (int i = 0; i < n; i++) {
                    if (i != col && mat[row][i] == 1) {
                        isOK = false;
                    }
                }

                if (isOK) ans++;
            }
        }

        return ans;
    }
};