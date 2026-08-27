class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int index = n - 1; index >= 0; index--) {
            int best = INT_MAX;

            for (int i = index; i < n; i++) {
                if (pal[index][i]) {
                    best = min(best, 1 + dp[i + 1]);
                }
            }

            dp[index] = best;
        }

        return dp[0] - 1;
    }
};
