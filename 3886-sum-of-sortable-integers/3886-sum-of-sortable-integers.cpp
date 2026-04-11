class Solution {
private:
    bool check(vector<int> &nums, int k) {
        int n = nums.size(), mini = 0;

        for (int i = 0; i < n; i += k) {
            if (nums[i] < mini) {
                return false;
            }

            int maxi = nums[i];
            bool flag = false;

            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] < mini) {
                    return false;
                }

                if (nums[j - 1] > nums[j]) {
                    if (flag) {
                        return false;
                    }
                    flag = true;
                }

                maxi = max(maxi, nums[j]);
            }

            if (flag) {
                if (nums[i] < nums[i + k - 1]) {
                    return false;
                }
            }

            mini = maxi;
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            if (check(nums, k)) {
                ans += k;
            }
        }

        return ans;
    }
};