class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> current(n + 1, 0), next(n + 1, 0);

        for (int index = n; index > 0; index--) {
            for (int prev_index = 0; prev_index <= index; prev_index++) {
                int len = next[prev_index];

                if (prev_index == 0 || nums[index - 1] > nums[prev_index - 1]) {
                    len = max(1 + next[index], len);
                }

                current[prev_index] = len;
            }
            next = current;
        }

        return current[0];
    }
};