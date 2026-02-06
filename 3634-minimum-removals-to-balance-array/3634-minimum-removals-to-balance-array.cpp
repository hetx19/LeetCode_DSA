class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), maxLength = 0, i = 0;
        sort(nums.begin(), nums.end());

        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
        }
        
        return n - maxLength;
    }
};