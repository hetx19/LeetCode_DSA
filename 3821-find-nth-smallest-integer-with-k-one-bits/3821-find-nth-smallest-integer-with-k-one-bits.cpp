class Solution {
public:
    long long nthSmallest(long long n, int k) {
        vector<vector<long long>> cost(60, vector<long long> (60, 0));

        for (int i = 0; i < 60; i++) {
            cost[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                cost[i][j] = cost[i - 1][j - 1] + cost[i - 1][j];
            }
        }

        long long ans = 0;

        for (int i = 50; i >= 0 && k > 0; i--) {
            if (n > cost[i][k]) {
                n -= cost[i][k];
                ans |= (1LL << i);
                k--;
            }
        }

        return ans;
    }
};