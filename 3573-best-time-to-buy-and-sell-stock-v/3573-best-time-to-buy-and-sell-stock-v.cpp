using ll = long long;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3, 0)));
        
        for (int K = 0; K <= k; K++) {
            dp[n][K][0] = 0;
            dp[n][K][1] = LLONG_MIN;
            dp[n][K][2] = LLONG_MIN;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int K = 0; K <= k; K++) {
                for (int d = 0; d < 3; d++) {
                    ll take = LLONG_MIN;
                    ll notTake = dp[i + 1][K][d];

                    if (K > 0) {
                        if (d == 1) {
                            if (dp[i + 1][K - 1][0] != LLONG_MIN) {
                                take = prices[i] + dp[i + 1][K - 1][0];
                            }
                        } else if (d == 2) {
                            if (dp[i + 1][K - 1][0] != LLONG_MIN) {
                                take = -prices[i] + dp[i + 1][K - 1][0];
                            }
                        } else {
                            if (dp[i + 1][K][2] != LLONG_MIN) {
                                take = prices[i] + dp[i + 1][K][2];
                            }

                            if (dp[i + 1][K][1] != LLONG_MIN) {
                                take = max(take, -prices[i] + dp[i + 1][K][1]);
                            }
                        }
                    }

                    dp[i][K][d] = max(take, notTake);
                }
            }
        }

        return dp[0][k][0];
    }
};