class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long sum = n * (n + 1) >> 1;
        long long sqSum = sum * ((2 * n) + 1) / 3;

        for (int num : nums) {
            sum -= (long long)num;
            sqSum -= (long long)(num * num);
        }

        sqSum /= sum;
        int missing = ((int)(sum + sqSum)) >> 1;
        int repeating = ((int)(sqSum - sum)) >> 1;

        return {repeating, missing};
    }
};