class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        for (auto query : queries) {
            int idx = query[0];

            while (idx <= query[1]) {
                nums[idx] = (1LL * nums[idx] * query[3]) % MOD;
                idx += query[2];
            }
        }

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};