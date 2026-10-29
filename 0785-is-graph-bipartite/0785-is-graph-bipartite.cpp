class Solution {
private:
    bool bfs(const vector<vector<int>> adjList, int start, vector<int>& color) {
        int V = adjList.size();

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &it : adjList[node]) {
                if (color[it] == -1) {
                    color[it] = (color[node] == 0) ? 1 : 0;
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        bool ans = true;

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfs(graph, i, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};