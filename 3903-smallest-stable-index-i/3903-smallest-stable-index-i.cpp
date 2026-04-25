class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            suffixMin[n - i - 1] = (i > 0) ? min(suffixMin[n - i], nums[n - i - 1]) : nums[n - i - 1];
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            if (maxi - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};