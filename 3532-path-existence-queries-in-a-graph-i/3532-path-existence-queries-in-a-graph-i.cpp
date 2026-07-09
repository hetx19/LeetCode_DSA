class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int V) {
        size.resize(V, 1);
        parent.resize(V);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);

        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                ds.unionBySize(i, i - 1);
            }
        }

        vector<bool> answer;

        for (auto &q : queries) {
            if (ds.findParent(q[0]) == ds.findParent(q[1])) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
        }

        return answer;
    }
};