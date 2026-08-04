class Solution {
  private:
	int longestCommonSubsequence(string text1, string text2) {
		int n1 = text1.size(), n2 = text2.size();
		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
		
		for (int index2 = 0; index2 <= n2; index2++) {
			dp[0][index2] = 0;
		}
		
		for (int index1 = 0; index1 <= n1; index1++) {
			dp[index1][0] = 0;
		}
		
		for (int index1 = 1; index1 <= n1; index1++) {
			for (int index2 = 1; index2 <= n2; index2++) {
				if (text1[index1 - 1] == text2[index2 - 1]) {
					dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
				} else {
					dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
				}
			}
		}
		
		return dp[n1][n2];
	}
	
	int longestPalindromeSubseq(string s) {
		string reversedString = s;
		reverse(reversedString.begin(), reversedString.end());
		return longestCommonSubsequence(s, reversedString);
	}
	
  public:
	int minInsertions(string s) {
		int n = s.size();
		return n - longestPalindromeSubseq(s);
	}
};