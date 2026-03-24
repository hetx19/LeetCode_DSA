class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prev(31, -1), next(31, n);
        vector<int> left(n, 0), right(n, n - 1);
        
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit < 31; bit++) {
                if ((nums[i] & (1 << bit)) == 0) {
                    left[i] = max(left[i], prev[bit] + 1);
                } else {
                    prev[bit] = i;
                }
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int bit = 0; bit < 31; bit++) {
                if ((nums[i] & (1 << bit)) == 0) {
                    right[i] = min(right[i], next[bit] - 1);
                } else {
                    next[bit] = i;
                }
            }
        }
        
        long long ans = 0;
        unordered_map<int, int> last;
        
        for (int i = 0; i < n; i++) {
            int l = left[i], r = right[i];
            
            if (last.count(nums[i])) {
                l = max(l, last[nums[i]] + 1);
            }
            last[nums[i]] = i;
            
            ans += 1LL * (i - l + 1) * (r - i + 1);
        }
        
        return ans;
    }
};