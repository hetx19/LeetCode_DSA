using ll = long long;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;

        for (int i = 0; i < n - 1; i++) {
            ans += max(0, nums[i] - nums[i + 1]);
        }

        return ans;
    }
};