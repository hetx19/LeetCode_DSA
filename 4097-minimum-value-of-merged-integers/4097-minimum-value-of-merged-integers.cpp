class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i += 2) {
            string merged = to_string(nums[i]) + to_string(nums[i + 1]);

            int num = stoi(merged);
            ans = min(ans, num);
        }

        return ans;
    }
};