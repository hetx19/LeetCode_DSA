class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;

        vector<int> left(n, 2), right(n, 2);

        for (int i = 2; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            int prev_diff = nums[i - 1] - nums[i - 2];

            if (prev_diff == diff) {
                left[i] = left[i - 1] + 1;
            } 
        }

        for (int i = n - 3; i >= 0; i--) {
            int prev_diff = nums[i + 2] - nums[i + 1];
            int diff = nums[i + 1] - nums[i];

            if (diff == prev_diff) {
                right[i] = right[i + 1] + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            ans = max(ans, max(left[i], right[i]));

            if (i == 0) {
                ans = max(ans, 1 + right[i + 1]);
            } else if (i == n - 1) {
                ans = max(ans, 1 + left[i - 1]);
            } else {
                ans = max(ans, 1 + right[i + 1]);
                ans = max(ans, 1 + left[i - 1]);

                if ((nums[i + 1] - nums[i - 1]) % 2 == 0) {
                    int required = (nums[i + 1] - nums[i - 1]) / 2;
                    int left_length = 1, right_length = 1;

                    if (i >= 2 && nums[i - 1] - nums[i - 2] == required) {
                        left_length = left[i - 1];
                    }

                    if (i < n - 2 && nums[i + 2] - nums[i + 1] == required) {
                        right_length = right[i + 1];
                    }

                    ans = max(ans, 1 + left_length + right_length);
                }
            }
        }

        return ans;
    }
};