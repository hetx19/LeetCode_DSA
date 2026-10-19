class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int countGreater = 0, countLower = 0;

        for (int &num : nums) {
            if (num < target) {
                countLower++;
            } else if (num > target) {
                countGreater++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n - countGreater - countLower; i++) {
            ans.push_back(i + countLower);
        }

        return ans;
    }
};