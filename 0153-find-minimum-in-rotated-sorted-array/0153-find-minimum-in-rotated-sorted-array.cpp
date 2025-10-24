class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while(low < high) {
            int mid = low + ((high - low) >> 1);

            if(nums[mid] > nums[high]) {
                // Minimum element is at right
                low = mid + 1;
            } else {
                // Minimum element is at left
                high = mid;
            }
        }

        return nums[low];
    }
};