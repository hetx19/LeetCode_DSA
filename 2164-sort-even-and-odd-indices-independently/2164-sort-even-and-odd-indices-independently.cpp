class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> oddIndices, evenIndices;

        for (int i = 0; i < n; i++) {
            if (i & 1) {
                oddIndices.push_back(nums[i]);
            } else {
                evenIndices.push_back(nums[i]);
            }
        }

        sort(oddIndices.rbegin(), oddIndices.rend());
        sort(evenIndices.begin(), evenIndices.end());

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (i & 1) {
                ans.push_back(oddIndices[(i >> 1)]);
            } else {
                ans.push_back(evenIndices[(i >> 1)]);
            }
        }

        return ans;
    }
};