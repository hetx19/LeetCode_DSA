using ll = long long;

class Solution {
private:
    int peekElement(vector<int> &nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        int low = 1, high = n - 2;

        if(nums[0] > nums[1]) {
            return 0;
        }

        if(nums[high + 1] > nums[high]) {
            return high + 1;
        }

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peekIdx = peekElement(nums);
        ll ascSum = 0, desSum = 0;

        for (int i = 0; i < n; i++) {
            if (i < peekIdx) {
                ascSum += nums[i];
            } else if (i > peekIdx) {
                desSum += nums[i];
            } else {
                ascSum += nums[i];
                desSum += nums[i];
            }
        }

        if (ascSum > desSum) {
            return 0;
        } else if (ascSum < desSum) {
            return 1;
        }

        return -1;
    }
};