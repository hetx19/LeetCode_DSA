class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size(), minDiff = INT_MAX;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            if (diff < minDiff) {
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
            } else if (diff == minDiff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }

        return ans;
    }
};