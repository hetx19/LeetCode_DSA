class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        int totalColored = 0;
        for (auto &src : sources) {
            int row = src[0];
            int col = src[1];
            int color = src[2];

            grid[row][col] = color;
            totalColored++;
            q.push({row, col});
        }

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, -1, 0, +1};

        while (!q.empty() && totalColored < (m * n)) {
            int size = q.size();
            map<pair<int,int>, int> update;
            
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = row + deltaRow[i];
                    int ncol = col + deltaCol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0) {
                        update[{nrow, ncol}] = max(update[{nrow, ncol}], grid[row][col]);
                    }
                }
            }

            for(auto &it : update){
                int row = it.first.first;
                int col = it.first.second;
                grid[row][col] = it.second;
                totalColored++;
                q.push({row, col});
            }
        }

        return grid;
    }
};