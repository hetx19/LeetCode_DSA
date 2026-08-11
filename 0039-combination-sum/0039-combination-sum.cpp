class Solution {
private:
    void solve(vector<int>& candidates, int index, int target, vector<int>& current, vector<vector<int>>& ans) {
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(current);
            }

            return;
        }

        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            solve(candidates, index, target - candidates[index], current, ans);
            current.pop_back();
        }

        solve(candidates, index + 1, target, current, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, temp, ans);

        return ans;
    }
};