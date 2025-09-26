class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;

        // For single element Array
        if(high == 0) {
            return nums[0];
        }
        
        // Trimming down the search space
        if(nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums[high] != nums[high - 1]) {
            return nums[high];
        }

        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // we are on left
                low = mid + 1;
            } else {
                // We are on right
                high = mid - 1;
            }
        }

        return -1;
    }
};