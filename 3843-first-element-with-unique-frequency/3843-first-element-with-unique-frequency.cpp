class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp1, mpp2;

        for (int num : nums) {
            mpp1[num]++;
        }

        for (auto it : mpp1) {
            mpp2[it.second]++;
        }

        for (int num : nums) {
            if (mpp2[mpp1[num]] == 1) {
                return num;
            }
        }
        
        return -1;
    }
};