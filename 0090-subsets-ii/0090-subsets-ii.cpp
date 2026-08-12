class Solution {
private:
    void solve(vector<int>& nums, int n, int index, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);

        for (int i = index; i < n; i++) {
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }

            ds.push_back(nums[i]);
            solve(nums, n, i + 1, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());

        solve(nums, n, 0, ds, ans);

        return ans;
    }
};