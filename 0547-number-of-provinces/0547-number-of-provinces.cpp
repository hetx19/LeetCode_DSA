class Solution {
private:
    void dfs(int node, vector<vector<int>> &adjLs, vector<bool> &visted) {
        visted[node] = true;

        for (auto neighbour : adjLs[node]) {
            if (!visted[neighbour]) {
                dfs(neighbour, adjLs, visted);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<bool> visted(V, false);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (visted[i] == false) {
                count++;
                dfs(i, adjLs, visted);
            }
        }

        return count;
    }
};