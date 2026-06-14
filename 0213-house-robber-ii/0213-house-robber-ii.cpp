class Solution {
private:
    int robber(vector<int>& nums) {
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

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n - 1) temp2.push_back(nums[i]);
        }

        return max(robber(temp1), robber(temp2));
    }
};