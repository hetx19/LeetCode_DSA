class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> ans(n, triangle[0][0]);

        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + triangle[i][i];
            for(int j = i - 1; j >= 1; j--) {
                ans[j] = triangle[i][j] + min(ans[j], ans[j-1]);
            }
            ans[0] += triangle[i][0];
        }

        return *min_element(ans.begin(), ans.end());
    }
};