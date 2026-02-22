class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int score1 = 0, score2 = 0;

        bool flag = true;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Rule 1:
            if (nums[i] & 1) {
                flag = !flag;
            }
            if (i % 6 == 5) {
                flag = !flag;
            }

            if (flag) {
                score1 += nums[i];
            } else {
                score2 += nums[i];
            }
        }
        return (score1 - score2);
    }
};