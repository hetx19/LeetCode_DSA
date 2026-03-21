class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total = 0;

        for (int num : nums) {
            total = (total + num) % p;
        }

        int target = total % p;
        if (target == 0) {
            return 0;
        }

        unordered_map<int, int> mpp;
        mpp[0] = -1;

        int current = 0, minLength = n;

        for (int i = 0; i < n; i++) {
            current = (current + nums[i]) % p;

            int rem = (current + p - target) % p;

            if (mpp.find(rem) != mpp.end()) {
                minLength = min(minLength, i - mpp[rem]);
            }

            mpp[current] = i;
        }

        return minLength == n ? -1 : minLength;
    }
};