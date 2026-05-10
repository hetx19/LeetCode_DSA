class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans = nums;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(ans[i]);
        }

        return ans;
    }
};