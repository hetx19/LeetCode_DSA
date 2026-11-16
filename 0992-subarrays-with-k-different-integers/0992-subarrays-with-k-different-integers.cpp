class Solution {
private:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ans = 0;

        int left = 0;

        for (int right = 0; right < n; right++) {
            mpp[nums[right]]++;

            while (mpp.size() > k) {
                mpp[nums[left]]--;

                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]); 
                }

                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};