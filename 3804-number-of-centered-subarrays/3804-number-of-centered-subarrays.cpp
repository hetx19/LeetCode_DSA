class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int subSum = 0;
            unordered_set<int> subNums;
            for (int j = i; j < n; j++) {
                subSum += nums[j];
                subNums.insert(nums[j]);
                ans += (subNums.find(subSum) != subNums.end());
            }
        }

        return ans;
    }
};