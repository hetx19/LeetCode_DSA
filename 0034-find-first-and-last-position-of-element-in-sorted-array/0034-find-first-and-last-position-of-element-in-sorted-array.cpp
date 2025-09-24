class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return first;
    }

    int lastOccurence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last = -1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // By using Raw Binary Search
        int first = firstOccurrence(nums, target);

        if(first == -1) {
            return {-1, -1};
        }

        int last = lastOccurence(nums, target);

        return {first, last};
    }
};