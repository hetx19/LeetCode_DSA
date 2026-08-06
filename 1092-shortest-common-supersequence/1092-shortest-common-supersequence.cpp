class Solution {
  public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int index1 = 1; index1 <= n1; index1++) {
            for (int index2 = 1; index2 <= n2; index2++) {
                if (str1[index1 - 1] == str2[index2 - 1]) {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

        string ans = "";
        int index1 = n1, index2 = n2;

        while (index1 > 0 && index2 > 0) {
            if (str1[index1 - 1] == str2[index2 - 1]) {
                ans += str1[index1 - 1];
                index1--;
                index2--;
            } else if (dp[index1 - 1][index2] > dp[index1][index2 - 1]) {
                ans += str1[index1 - 1];
                index1--;
            } else {
                ans += str2[index2 - 1];
                index2--;
            }
        }

        while (index1 > 0) {
            ans += str1[index1 - 1];
            index1--;
        }

        while (index2 > 0) {
            ans += str2[index2 - 1];
            index2--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};