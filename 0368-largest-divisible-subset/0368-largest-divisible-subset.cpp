class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n , 1), hash(n);
        int maxi = 1, lastIndex = 0;

        for (int index = 0; index < n; index++) {
            hash[index] = index;

            for (int prev = 0; prev < index; prev++) {
                if (nums[index] % nums[prev] == 0 && 1 + dp[prev] > dp[index]) {
                    dp[index] = 1 + dp[prev];
                    hash[index] = prev;
                }
            }

            if (dp[index] > maxi) {
                maxi = dp[index];
                lastIndex = index;
            }
        }

        vector<int> LDS;
        LDS.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            LDS.push_back(nums[lastIndex]);
        }

        return LDS;
    }
};