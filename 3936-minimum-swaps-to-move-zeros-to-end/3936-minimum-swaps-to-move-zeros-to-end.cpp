class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int numberOfZeroes = 0;

        for (int num : nums) {
            if (num == 0) {
                numberOfZeroes++;
            }
        }

        int n = nums.size() - 1;
        int bc = 0;

        int temp = numberOfZeroes;

        while (temp--) {
            if (nums[n] == 0) {
                bc++;
            }
            n--;
        }

        return numberOfZeroes - bc;
    }
};