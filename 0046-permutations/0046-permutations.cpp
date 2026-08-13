class Solution {
private:
    void solve(vector<int>& nums, int n, int index, vector<vector<int>>& ans) {
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            solve(nums, n, index + 1, ans);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        solve(nums, n, 0, ans);

        return ans;
    }
};