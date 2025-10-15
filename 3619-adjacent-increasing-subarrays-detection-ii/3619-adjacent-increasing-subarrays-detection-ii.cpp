class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1, ans = 0, previous = 0;

        while(j < n) {
            if (nums[j] <= nums[j - 1]) {
                ans = max({ans, (j - i) / 2, min (previous, j - i)});
                previous = j - i;
                i = j;
            }
            j++;
        }
        ans = max({ans, (j-i)/2, min (previous, j-i)});

        return ans;
    }
};