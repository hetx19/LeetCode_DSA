class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0, forb = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int test = forb | (1 << bit);

            bool possible = true;

            for (auto row : grid) {
                bool found = false;

                for (int num : row) {
                    if ((num & test) == 0) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                forb = test;
            } else {
                ans |= (1 << bit);
            }
        }

        return ans;
    }
};