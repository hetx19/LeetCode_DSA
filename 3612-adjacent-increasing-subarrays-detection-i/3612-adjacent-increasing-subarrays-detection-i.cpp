class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), increase = 1, previousI = 0, maxLen = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                increase++;
            } else {
                previousI = increase;
                increase = 1;
            }
            maxLen = max(maxLen, max(increase >> 1, min(increase, previousI)));

            if(maxLen >= k) {
                return true;
            } 
        }

        return false;
    }
};