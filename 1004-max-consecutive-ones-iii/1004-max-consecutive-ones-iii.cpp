class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLength = 0;
        int left = 0;

        int converted = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 1) {
                maxLength = max(maxLength, right - left + 1);
            } else {
                if (converted < k) {
                    converted++;
                } else {
                    while (nums[left] == 1) {
                        left++;
                    }
                    left++;
                }
                
                maxLength = max(maxLength, right - left + 1);
            }
        }

        return maxLength;
    }
};