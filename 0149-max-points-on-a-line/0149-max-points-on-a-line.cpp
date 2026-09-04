class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            map<double, int> mpp;

            for (int j = i + 1; j < n; j++) {
                double slope = (double)(points[j][1] - points[i][1]) / (double)(double)(points[j][0] - points[i][0]);

                if (points[j][1] - points[i][1] < 0 && (points[j][0] - points[i][0]) == 0) {
                    mpp[abs(slope)]++;
                } else {
                    mpp[slope]++;
                }
            }

            int temp = 0;

            for (auto &it : mpp) {
                temp = max(temp, it.second + 1);
            }

            ans = max(temp, ans);
        }

        return ans;
    }
};