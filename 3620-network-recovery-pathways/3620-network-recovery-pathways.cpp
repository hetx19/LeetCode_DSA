using ll = long long;

class Solution {
public:
    bool check(int mid, vector<vector<pair<int, int>>>& adj, vector<int>& deg, int n, ll k) {
        vector<ll> dp(n, LLONG_MAX / 2);
        vector<int> cdeg = deg;

        dp[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == n - 1) {
                return dp[u] <= k;
            }

            for (auto &[v, w] : adj[u]) {
                if (w >= mid) {
                    dp[v] = min(dp[v], dp[u] + w);
                }

                cdeg[v]--;
                if (cdeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        vector<int> deg(n, 0);

        int low = INT_MAX, high = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (!online[u] || !online[v])
                continue;

            adj[u].push_back({v, w});
            deg[v]++;

            low = min(low, w);
            high = max(high, w);
        }

        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &[v, w] : adj[u]) {
                deg[v]--;
                if (v && deg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (!check(low, adj, deg, n, k)) {
            return -1;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, adj, deg, n, k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};