class Solution {
private:
    int lcs(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int index1 = 1; index1 <= n1; index1++) {
            for (int index2 = 1; index2 <= n2; index2++) {
                if (word1[index1 - 1] == word2[index2 - 1]) {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

        return dp[n1][n2];
    }

public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int lenghtOfLcs = lcs(word1, word2);
        
        return (n1 + n2 - (2 * lenghtOfLcs));
    }
};