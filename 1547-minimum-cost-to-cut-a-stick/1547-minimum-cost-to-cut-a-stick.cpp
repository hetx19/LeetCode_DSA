class Solution {
private:
    int solve(vector<int>& cuts, int start, int end, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int mini = INT_MAX;

        for (int index = start; index <= end; index++) {
            int cost = (cuts[end + 1] - cuts[start - 1]) + solve(cuts, start, index - 1, dp) + solve(cuts, index + 1, end, dp);

            mini = min(mini, cost);
        }

        return dp[start][end] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int length = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(length + 1, vector<int>(length + 1, - 1));

        return solve(cuts, 1, length, dp);
    }
};