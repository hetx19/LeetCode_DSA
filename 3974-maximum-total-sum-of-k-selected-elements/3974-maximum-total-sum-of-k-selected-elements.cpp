using ll = long long;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());

        ll ans = 0;
        int count = min(k , mul-1);
        k = k - count;

        int i = 0;
        while (count--) {
            ans += (1LL * nums[i] * mul);
            i++;
            mul--;
        }

        while (k > 0) {
            ans += nums[i];
            i++;
            k--;
        }

        return ans;
    }
};