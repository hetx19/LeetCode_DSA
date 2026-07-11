class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            queue<int> q;
            q.push(i);
            visited[i] = true;

            int nodes = 0;
            int edgeCount = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                nodes++;
                edgeCount += adj[u].size();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            edgeCount /= 2;

            if (edgeCount == nodes * (nodes - 1) / 2) {
                ans++;
            }
        }

        return ans;
    }
};