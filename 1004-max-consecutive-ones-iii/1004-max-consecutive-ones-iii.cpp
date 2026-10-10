class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLength = 0;
        int left = 0;

        int zeros = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeros++;
            }

            if (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }

                left++;
            }

            if (zeros <= k) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        return maxLength;
    }
};