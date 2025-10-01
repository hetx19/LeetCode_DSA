class Solution {
public:
    int splitArrayIntoSubarrays(vector < int > & nums, int maxSubarraySum) {
        int subarrays = 1, currentSubarraySum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (currentSubarraySum + nums[i] <= maxSubarraySum) {
                currentSubarraySum += nums[i];
            } else {
                subarrays += 1;
                currentSubarraySum = nums[i];
            }
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) {
            return -1;
        }
        
        int low = * max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0);
        
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int numSubarrays = splitArrayIntoSubarrays(nums, mid);
            
            if (numSubarrays > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};