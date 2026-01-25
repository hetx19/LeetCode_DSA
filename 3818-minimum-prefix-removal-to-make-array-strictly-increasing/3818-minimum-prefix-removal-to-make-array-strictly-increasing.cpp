class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        while (n > 1 && nums[n - 2] < nums[n - 1]) {
            n--;
        }
        return n - 1;
    }
};