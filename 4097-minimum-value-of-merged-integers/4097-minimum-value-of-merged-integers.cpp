class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i += 2) {
            string merged = to_string(nums[i]) + to_string(nums[i + 1]);

            int num = stoll(merged);
            ans = min(ans, num);
        }

        return ans;
    }
};