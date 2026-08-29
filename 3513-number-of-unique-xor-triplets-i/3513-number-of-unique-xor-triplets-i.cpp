class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) {
            return n;
        }

        int mask = 0;

        while(n > 1) {
            n >>= 1;
            mask++;
        }

        return 1 << (mask + 1);
    }
};