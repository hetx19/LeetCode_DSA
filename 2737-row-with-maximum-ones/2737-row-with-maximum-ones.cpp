class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count_max = -1, index = -1;
        int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < n; i++) {
            int count_ones = 0;

            for(int j = 0; j < m; j++) {
                count_ones += mat[i][j];
                if(count_ones > count_max) {
                    count_max = count_ones;
                    index = i;
                }
            }
        }
        
        return {index, count_max};
    }
};