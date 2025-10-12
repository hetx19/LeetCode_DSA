class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        int freq[101] = {0};

        // Pre storing frequencies in a map data structure
        for(int x : nums) {
            freq[x]++;
        }

        for(int i = 0; i < 100; i++) {
            if(freq[i + 1] % k == 0) {
                sum += ((i + 1) * freq[i + 1]);
            }
        }

        return sum;
    }
};