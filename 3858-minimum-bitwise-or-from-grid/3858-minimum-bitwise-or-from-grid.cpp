class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = (1 << 20) - 1;

        for (int bit = 19; bit >= 0; bit--) {
            int nans = ans ^ (1 << bit);
            bool isPossible = true;

            for (auto &row : grid) {
                bool sub = false;
                for (auto num : row) {
                    if ((nans | num) == nans) {
                        sub = true;
                    }
                }
                if (!sub) {
                    isPossible = false;
                }
            }
            if (!isPossible) {
                continue;
            }
            ans = nans;
        }

        return ans;
    }
};