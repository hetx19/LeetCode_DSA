class DisjointSet {
  public:
    vector<int> parent, size;

    DisjointSet(int V) {
        parent.resize(V);
        size.resize(V, 1);

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

    void unionBySize(int u, int v) {
        int pu = findParent(u), pv = findParent(v);

        if (pu == pv) {
            return;
        }

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, -1, 0, +1};

        DisjointSet ds(n * n);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;

                for (int i = 0; i < 4; i++) {
                    int nrow = row + deltaRow[i];
                    int ncol = col + deltaCol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                        ds.unionBySize(n * nrow + ncol, n * row + col);
                    }
                }
            }
        }

        int ans = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;

                set<int> components;

                for (int i = 0; i < 4; i++) {
                    int nrow = row + deltaRow[i];
                    int ncol = col + deltaCol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                        components.insert(ds.findParent(nrow * n + ncol));
                    }
                }

                int size = 0;
                for (auto &it : components) {
                    size += ds.size[it];
                }

                ans = max(ans, size + 1);
            }
        }

        for (int i = 0; i < n * n; i++) {
            ans = max(ans, ds.size[ds.findParent(i)]);
        }

        return ans;
    }
};