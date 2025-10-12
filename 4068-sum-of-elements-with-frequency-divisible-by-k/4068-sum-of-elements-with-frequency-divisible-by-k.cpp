class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        unordered_map<int, int> numFreqMap;

        // Pre storing frequencies in a map data structure
        for(int i = 0; i < n; i++) {
            numFreqMap[nums[i]]++;
        }

        for(auto it : numFreqMap) {
            if(it.second % k == 0) {
                sum += (it.first * it.second);
            }
        }

        return sum;
    }
};