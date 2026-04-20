class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int low = -1;
        int n = nums.size();
        int element;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1 || nums[i] == 2) {
                low = i;
                element = nums[i];
                break;
            }
        }

        if (low == -1) {
            return -1;
        }

        int minDifference = INT_MAX;

        for (int j = low + 1; j < n; j++) {
            if (nums[j] == (3 - element)) {
                minDifference = min(minDifference, j - low);
                low = j;
                element = nums[j];
            } else if (nums[j] == element) {
                low = j;
            }
        }

        return (minDifference == INT_MAX) ? -1 : minDifference;
    }
};