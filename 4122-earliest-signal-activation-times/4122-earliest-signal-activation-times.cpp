using ll = long long;

class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[2], e[1]});
        }

        vector<ll> ans(n, -1);
        ans[0] = 0;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        for (auto& [d, v] : adj[0]) {
            pq.push({d, v});
        }

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (ans[u] >= 0) {
                continue;
            }

            if (--requiredSignals[u] == 0) {
                ans[u] = t;

                for (auto& [d, v] : adj[u]) {
                    if (ans[v] < 0) {
                        pq.push({t + d, v});
                    }
                }
            }
        }

        return ans;
    }
};