class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int dp1 = 0;
        int dp2 = 0;
        int dp3 = 0;

        for (int index = n - 1; index >= 0; index--) {
            int cost = dp1 + costs[index] + 1;

            if (index + 2 <= n) {
                cost = min(cost, dp2 + costs[index + 1] + 4);
            }

            if (index + 3 <= n) {
                cost = min(cost, dp3 + costs[index + 2] + 9);
            }

            dp3 = dp2;
            dp2 = dp1;
            dp1 = cost;
        }

        return dp1;
    }
};