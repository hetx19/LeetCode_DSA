class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int length = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(length + 2, vector<int>(length + 2, 0));

        for (int start = length; start > 0; start--) {
            for (int end = 1; end <= length; end++) {
                if (start > end) {
                    continue;
                }

                int mini = INT_MAX;

                for (int index = start; index <= end; index++) {
                    int cost = (cuts[end + 1] - cuts[start - 1]) + dp[start][index - 1] + dp[index + 1][end];

                    mini = min(cost, mini);
                }

                dp[start][end] = mini;
            }
        }

        return dp[1][length];
    }
};