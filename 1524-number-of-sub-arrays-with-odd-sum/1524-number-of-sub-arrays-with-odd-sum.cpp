using ll = long long;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int even = 1, odd = 0;

        ll ans = 0;
        int parity = 0;

        for (int &num : arr) {
            parity = (parity + num) & 1;

            if (parity == 1) {
                ans = (ans + even) % MOD;
                odd++;
            } else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return (int)ans;
    }
};