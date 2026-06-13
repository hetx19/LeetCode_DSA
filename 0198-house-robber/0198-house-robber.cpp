class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0], prev2 = 0;

        for (int i = 1; i < n; i++) {
            int take = nums[i] + ((i > 1) ? prev2 : 0);
            int not_take = prev;

            int curri = max(take, not_take);
            prev2 = prev;
            prev = curri;
        }

        return prev;
    }
};