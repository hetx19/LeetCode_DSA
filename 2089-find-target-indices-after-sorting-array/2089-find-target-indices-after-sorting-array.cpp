class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        vector<int> ans;
        for (int i = lower; i < upper; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};