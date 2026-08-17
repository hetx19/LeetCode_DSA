class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int length = 0;

        for (int num : nums) {
            if (temp.empty() || num > temp.back()) {
                temp.push_back(num);
                length++;
            } else {
                temp[lower_bound(temp.begin(), temp.end(), num) - temp.begin()] = num;
            }
        }

        return length;
    }
};