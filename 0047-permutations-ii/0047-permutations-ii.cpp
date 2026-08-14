class Solution {
public:
    void solve(vector<int>& nums, int index, vector<vector<int>>& ans) {
        int n = nums.size();

        if (index == n) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = index; i < n; i++) {
            if (used.count(nums[i])) {
                continue;
            }

            used.insert(nums[i]);

            swap(nums[i], nums[index]);
            solve(nums, index + 1, ans);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};