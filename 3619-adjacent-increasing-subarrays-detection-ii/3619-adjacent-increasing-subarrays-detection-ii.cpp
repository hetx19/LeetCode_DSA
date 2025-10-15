class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1, pervious_cnt = 0, ans = 0;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] > nums[i]) {
                cnt++;
            } else {
                pervious_cnt = cnt;
                cnt = 1;
            }

            ans = max(max(ans, min(pervious_cnt, cnt)), cnt / 2);
        }

        return ans;
    }
};