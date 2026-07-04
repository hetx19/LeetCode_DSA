class Solution {
private:
    int find(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent, parent[node]);
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parent(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& r : roads) {
            parent[find(parent, r[0])] = find(parent, r[1]);
        }

        int res = 10001;

        for (auto& r : roads) {
            if (find(parent, r[0]) == find(parent, 1)) {
                res = min(res, r[2]);
            }
        }

        return res;
    }
};