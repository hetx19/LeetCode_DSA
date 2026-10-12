class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int correctSize = n;

        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] != val) {
                swap(nums[j], nums[i]);
                i++;
            }
            j++;
        }

        return i++;
    }
};