class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int V = matrix.size();
        vector<int> degree(V);

        for (int i = 0; i < V; i++) {
            degree[i] = count(matrix[i].begin(), matrix[i].end(), 1);
        }

        return degree;
    }
};