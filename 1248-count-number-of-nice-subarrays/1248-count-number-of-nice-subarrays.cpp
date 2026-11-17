class Solution {
private:
    int solve(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }

        int n = nums.size(), sum = 0, ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += (nums[right] & 1);

            while (sum > k) {
                sum -= (nums[left] & 1);
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};