class Solution {
private:
    int solve(vector<int>& nums, int n, int index, int currentXOR) {
        if (index == n) {
            return currentXOR;
        }

        int take = solve(nums, n, index + 1, currentXOR ^ nums[index]);
        int notTake = solve(nums, n, index + 1, currentXOR);

        return take + notTake;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        return solve(nums, n, 0, 0);
    }
};