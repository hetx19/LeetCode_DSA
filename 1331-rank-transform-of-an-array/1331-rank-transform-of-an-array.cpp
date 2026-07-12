class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (int &a : arr) {
            a = lower_bound(nums.begin(), nums.end(), a) - nums.begin() + 1;
        }

        return arr;
    }
};