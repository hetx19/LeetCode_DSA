class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if (k == 1) {
            return r - l + 1;
        }

        int ans = 0, maxi = pow(r, 1.0 / k) + 1;

        for (int x = 0; x <= maxi; x++) {
            long long y = pow(x, k);
            if (l <= y && y <= r) {
                ans++;
            }
        }

        return ans;
    }
};