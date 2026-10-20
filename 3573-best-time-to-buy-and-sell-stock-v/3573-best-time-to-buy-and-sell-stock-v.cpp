using ll = long long;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<ll>> current(k + 1, vector<ll>(3, 0)), next(k + 1, vector<ll>(3, 0));
        
        for (int K = 0; K <= k; K++) {
            next[K][0] = 0;
            next[K][1] = LLONG_MIN;
            next[K][2] = LLONG_MIN;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int K = 0; K <= k; K++) {
                for (int d = 0; d < 3; d++) {
                    ll take = LLONG_MIN;
                    ll notTake = next[K][d];

                    if (K > 0) {
                        if (d == 1) {
                            if (next[K - 1][0] != LLONG_MIN) {
                                take = prices[i] + next[K - 1][0];
                            }
                        } else if (d == 2) {
                            if (next[K - 1][0] != LLONG_MIN) {
                                take = -prices[i] + next[K - 1][0];
                            }
                        } else {
                            if (next[K][2] != LLONG_MIN) {
                                take = prices[i] + next[K][2];
                            }

                            if (next[K][1] != LLONG_MIN) {
                                take = max(take, -prices[i] + next[K][1]);
                            }
                        }
                    }

                    current[K][d] = max(take, notTake);
                }
            }

            next = current;
        }

        return current[k][0];
    }
};