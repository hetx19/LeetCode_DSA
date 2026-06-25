using ll = long long;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(2 * n + 1, 0);

        prefix[n] = 1;

        int count = n;
        ll preSum = 0, ans = 0;

        for (int &x : nums) {
            if (x == target) {
                preSum += prefix[count];
                count++;

                prefix[count]++;
            } else {
                count--;
                preSum -= prefix[count];
                prefix[count]++;
            }

            ans += preSum;
        }

        return ans;
    }
};