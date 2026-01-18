class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 1; i <= 100; i++) {
            freq[i] += freq[i - 1];
        }


        vector<int> ans;
        for (int num : nums) {
            ans.push_back(num == 0 ? 0 : freq[num - 1]);
        }

        return ans;
    }
};