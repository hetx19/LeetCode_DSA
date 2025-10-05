class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n * n;
        int xr = 0;

        for(int i = 0; i < size; i++) {
            xr = xr ^ grid[i / n][i % n];
            xr = xr ^ (i + 1);
        }

        int number = (xr & ~(xr - 1));
        int zero = 0, one = 0;

        for(int i = 0; i < size; i++) {
            if((grid[i / n][i % n] & number) != 0) {
                one = one ^ grid[i / n][i % n];
            } else {
                zero = zero ^ grid[i / n][i % n];
            }

            if(((i + 1) & number) != 0) {
                one = one ^ (i + 1);
            } else {
                zero = zero ^ (i + 1);
            }
        }

        int cnt = 0;
        for(int i = 0; i < size; i++) {
            if(grid[i / n][i % n] == zero) {
                cnt++;
            }
        }

        if(cnt == 2) {
            return {zero, one};
        }
        return {one, zero};
    }
};