class Solution {
private:
    void solve(int n, int k, int start, vector<int>& combination, vector<vector<int>>& ans) {
        if (combination.size() == k) {
            ans.push_back(combination);
            return;
        }

        for (int nums = start; nums <= n; nums++) {
            combination.push_back(nums);
            solve(n, k, nums + 1 , combination, ans);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combination;

        solve(n, k, 1, combination, ans);
        return ans;
    }
};