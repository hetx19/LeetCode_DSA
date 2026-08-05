class Solution {
private:
    int solve(string word1, int index1, string word2, int index2, vector<vector<int>>& dp) {
        if (index1 == 0 || index2 == 0) {
            return dp[index1][index2] = 0;
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        if (word1[index1 - 1] == word2[index2 - 1]) {
            return dp[index1][index2] = 1 + solve(word1, index1 - 1, word2, index2 - 1, dp);
        }

        return dp[index1][index2] = max(solve(word1, index1 - 1, word2, index2, dp), solve(word1, index1, word2, index2 - 1, dp));
    }

    int lcs(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return solve(word1, n1, word2, n2, dp);
    }

public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int lenghtOfLcs = lcs(word1, word2);
        
        return (n1 + n2 - (2 * lenghtOfLcs));
    }
};