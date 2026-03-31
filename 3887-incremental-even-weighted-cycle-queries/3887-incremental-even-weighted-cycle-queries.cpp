class Solution {
private:
    int findParent(vector<int>& parent, vector<int>& xorToParent, int node) {
        if (parent[node] != node) {
            int root = findParent(parent, xorToParent, parent[node]);

            xorToParent[node] ^= xorToParent[parent[node]];
            parent[node] = root;
        }

        return parent[node];
    }

public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> xorToParent(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int validEdges = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            int rootU = findParent(parent, xorToParent, u);
            int rootV = findParent(parent, xorToParent, v);

            if (rootU != rootV) {
                parent[rootU] = rootV;

                xorToParent[rootU] = xorToParent[u] ^ xorToParent[v] ^ weight;

                validEdges++;
            } else {
                if ((xorToParent[u] ^ xorToParent[v] ^ weight) == 0) {
                    validEdges++;
                }
            }
        }

        return validEdges;
    }
};