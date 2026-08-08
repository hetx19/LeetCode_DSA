class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;

        vector<int> mpp(k, 0);
        mpp[0] = 1;

        int sum = 0;

        for (int num : nums) {
            sum += num;
            int reminder = ((sum % k) + k) % k ;
            ans += mpp[reminder];
            mpp[reminder]++;
        }

        return ans;
    }
};