class Solution {
  public:
	int numDistinct(string s, string t) {
		int n1 = s.size(), n2 = t.size();
		vector<vector<double>> dp(n1 + 1, vector<double>(n2 + 1, 0));
		
		for (int index1 = 0; index1 <= n1; index1++) {
			dp[index1][0] = 1;
		}
		
		for (int index1 = 1; index1 <= n1; index1++) {
			for (int index2 = 1; index2 <= n2; index2++) {
				if (s[index1 - 1] == t[index2 - 1]) {
					dp[index1][index2] = dp[index1 - 1][index2 - 1] + dp[index1 - 1][index2];
				} else {
					dp[index1][index2] = dp[index1 - 1][index2];
				}
			}
		}
		
		return (int)(dp[n1][n2]);
	}
};