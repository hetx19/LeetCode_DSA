class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int suffixSum = accumulate(nums.begin(), nums.end(), 0);
        int preffixSum = 0;

        for (int i = 0; i < n; i++) {
            ans[i] = abs(preffixSum - suffixSum + nums[i]);
            preffixSum += nums[i];
            suffixSum -= nums[i];
        }

        return ans;
    }
};