class Solution {
  private:
	int solve(string s, int index1, string t, int index2, vector<vector<int>>& dp) {
		if (index2 < 0) {
			return 1;
		}
		
		if (index1 < 0) {
			return 0;
		}
		
		if (dp[index1][index2] != -1) {
			return dp[index1][index2];
		}
		
		if (s[index1] == t[index2]) {
			return dp[index1][index2] = solve(s, index1 - 1, t, index2 - 1, dp) + solve(s, index1 - 1, t, index2, dp);
		}
		
		return dp[index1][index2] = solve(s, index1 - 1, t, index2, dp);
	}
	
  public:
	int numDistinct(string s, string t) {
		int n1 = s.size(), n2 = t.size();
		vector<vector<int>> dp(n1, vector<int>(n2, -1));
		
		return solve(s, n1 - 1, t, n2 - 1, dp);
	}
};