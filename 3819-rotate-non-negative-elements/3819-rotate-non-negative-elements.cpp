class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for (int num : nums) {
            if (num >= 0) {
                ans.push_back(num);
            }
        }

        if (ans.empty()) {
            return nums;
        }

        k = k % (ans.size());
        rotate(ans.begin(), ans.begin() + k, ans.end());

        int i = 0;
        for (int &num : nums) {
            if (num >= 0) {
                num = ans[i++];
            }
        }

        return nums;
    }
};