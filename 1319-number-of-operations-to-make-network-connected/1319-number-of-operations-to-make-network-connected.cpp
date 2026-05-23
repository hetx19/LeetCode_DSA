class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int V) {
        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u), pv = findParent(v);

        if (pu == pv) {
            return;
        }

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numberOfEdges = connections.size();
        int cntExtraEdges = 0;
        int numberOfConnectedComponents = 0;
        DisjointSet ds(n);

        for (auto &e : connections) {
            int u = e[0];
            int v = e[1];

            if (ds.findParent(u) == ds.findParent(v)) {
                cntExtraEdges++;
            } else {
                ds.unionByRank(u, v);
            }
        }

        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                numberOfConnectedComponents++;
            }
        }

        int ans = numberOfConnectedComponents - 1;

        if (cntExtraEdges >= ans) {
            return ans;
        }

        return -1;
    }
};