class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        long long ans = 0;

        int right1 = -1, right2 = -1, count = 0;
        unordered_map<int, int> mpp1, mpp2;

        for (int i = 0; i < n; i++) {
            while (right2 < n && mpp1.size() < k + 1) {
                right2++;
                if (right2 < n) {
                    mpp1[nums[right2]]++;
                }
            }
            while (right1 < n && count < k) {
                right1++;
                if (right1 < n) {
                    mpp2[nums[right1]]++;
                    if (mpp2[nums[right1]] == m) {
                        count++;
                    }
                }
            }

            if (right1 < right2) {
                ans += (right2 - right1);
            }

            mpp1[nums[i]]--;
            if (!mpp1[nums[i]]) {
                mpp1.erase(nums[i]);
            }

            mpp2[nums[i]]--;
            if (mpp2[nums[i]] == m - 1) {
                count--;
            }
        }

        return ans;
    }
};