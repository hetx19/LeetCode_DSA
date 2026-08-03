class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = size(stoneValue);
        vector<int> dp(3, 0);
        dp[0] = stoneValue[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int result = stoneValue[i] - dp[0];
            result = max(result, stoneValue[i] + stoneValue[i + 1] - dp[1]);
            if (i + 2 < n) {
                result = max(result, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[2]);
            }
            
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = result;
        }

        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] == 0) {
            return "Tie";
        }

        return "Bob";
    }
};