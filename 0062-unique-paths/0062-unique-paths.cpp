using ll = long long;

class Solution {
private:
    int nCr(int n, int r) {
        ll ans = 1;

        for (int i = 0; i < r; i++) {
            ans = ans * (n - i);
            ans = ans / (i + 1);
        }

        return (int)ans;
    }

public:
    int uniquePaths(int m, int n) {
        // By using simple mathematics
        int len = max(m - 1, n - 1);
        int bre = min(m - 1, n - 1);

        int ans = nCr(len + bre, bre);

        return ans;
    }
};