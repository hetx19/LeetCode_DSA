class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums;
        }
        
        vector<int> prefix(n, INT_MIN), suffix(n, INT_MIN); 

        for (int i = 0; i < n; i++) {
            prefix[i] = (i > 0) ? max(prefix[i - 1], nums[i]) : nums[0];
            suffix[n - i - 1] = (i > 0) ? max(suffix[n - i], nums[n - i - 1]) : nums[n - i - 1];
        }
        
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > prefix[i - 1] || nums[i] > suffix[i + 1]) {
                ans.push_back(nums[i]);
            }
        }
        ans.push_back(nums[n - 1]);

        return ans;
    }
};