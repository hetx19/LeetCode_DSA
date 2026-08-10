class Solution {
private:
    void generateSubset(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& ans) {
        if (index < 0) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        generateSubset(nums, index - 1, subset, ans);
        subset.pop_back();

        generateSubset(nums, index - 1, subset, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;
        generateSubset(nums, n - 1, subset, ans);

        return ans;
    }
};