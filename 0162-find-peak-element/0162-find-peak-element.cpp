class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 1, high = nums.size() - 2;

        // Single element Array
        if(nums.size() == 1) {
            return 0;
        }

        // Trimming down search space
        if(nums[0] > nums[1]) {
            return 0;
        }
        if(nums[high + 1] > nums[high]) {
            return high + 1;
        }

        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if(nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};