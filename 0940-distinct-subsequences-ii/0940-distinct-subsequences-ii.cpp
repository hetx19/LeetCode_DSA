class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        int ans = 0;
        vector<int> dp(26, 0);

        for (char &ch : s) {
            int newSubsequences = (ans - dp[ch - 'a'] + MOD) % MOD;
            dp[ch - 'a'] = 1 + ans;
            ans = (dp[ch - 'a'] + newSubsequences) % MOD;
        }

        return ans;
    }
};