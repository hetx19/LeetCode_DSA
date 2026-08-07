class Solution {
  public:
	int numDistinct(string s, string t) {
		int n1 = s.size(), n2 = t.size();
		vector<double> dp(n2 + 1, 0);
		
		dp[0] = 1;
		
		for (int index1 = 1; index1 <= n1; index1++) {
			for (int index2 = n2; index2 > 0; index2--) {
				if (s[index1 - 1] == t[index2 - 1]) {
					dp[index2] = dp[index2 - 1] + dp[index2];
				}
			}
		}
		
		return (int)(dp[n2]);
	}
};