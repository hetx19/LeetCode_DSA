class Solution {
private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int n = nums.size();
        int ans = 0, sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left++];
            }

            ans += right - left + 1;
        }

        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};