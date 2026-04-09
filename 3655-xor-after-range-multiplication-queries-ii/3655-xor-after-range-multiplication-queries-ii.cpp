class Solution {
    const int MOD = 1e9 + 7;

private:
    int pow(long long x, long long y) {
        long long ans = 1;
        for (; y; y >>= 1) {
            if (y & 1) ans = (ans * x) % MOD;
            x = (x * x) % MOD;
        }

        return ans;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sq_n = sqrt(n);

        vector<vector<vector<int>>> ans(sq_n);

        for (auto &query : queries) {
            if (query[2] < sq_n) {
                ans[query[2]].push_back({query[0], query[1], query[3]});
            } else {
                for (int i = query[0]; i <= query[1]; i += query[2]) {
                    nums[i] = (1LL * nums[i] * query[3]) % MOD;
                }
            }
        }

        vector<long long> differnce(n + sq_n);
        for (int i = 1; i < sq_n; i++) {
            if (ans[i].empty()) continue;

            fill(differnce.begin(), differnce.end(), 1);

            for (auto &query : ans[i]) {
                int l = query[0], r = query[1], v = query[2];
                differnce[l] = (differnce[l] * v) % MOD;
                int R = ((r - l) / i + 1) * i + l;
                differnce[R] = differnce[R] * pow(v, MOD - 2) % MOD;
            }

            for (int j = i; j < n; j++) {
                differnce[j] = (differnce[j] * differnce[j - i]) % MOD;
            }

            for (int j = 0; j < n; j++) {
                nums[j] = (1LL * nums[j] * differnce[j]) % MOD;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result = result ^ nums[i];
        }

        return result;
    }
};