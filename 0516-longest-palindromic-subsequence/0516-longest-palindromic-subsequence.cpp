class Solution {
  private:
    int solve(string text1, int index1, string text2, int index2, vector<vector<int>>& dp) {
        if (index1 == 0 || index2 == 0) {
            return dp[index1][index2] = 0;
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        if (text1[index1 - 1] == text2[index2 - 1]) {
            return dp[index1][index2] = 1 + solve(text1, index1 - 1, text2, index2 - 1, dp);
        }

        return dp[index1][index2] = max(solve(text1, index1 - 1, text2, index2, dp), solve(text1, index1, text2, index2 - 1, dp));
    }

	int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int index1 = 1; index1 <= n1; index1++) {
            for (int index2 = 1; index2 <= n2; index2++) {
                if (text1[index1 - 1] == text2[index2 - 1]) {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

		return dp[n1][n1];
	}
	
  public:
	int longestPalindromeSubseq(string s) {
		string reversedString = s;
		reverse(reversedString.begin(), reversedString.end());
		return longestCommonSubsequence(s, reversedString);
	}
};