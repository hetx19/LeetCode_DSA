using ll = long long;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mini = INT_MAX;

        int mx = 0;
        for (auto &it : items) {
            mx = max(mx, it[0]);
            mini = min(mini, it[1]);
        }

        vector<ll> count(mx + 1, 0);

        for (auto &it : items) {
            count[it[0]]++;
        }

        vector<ll> multiply(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            for (int m = i; m <= mx; m += i) {
                multiply[i] += count[m];
            }
        }

        map<int, ll> mpp;

        for (auto &it : items) {
            int a = it[0];
            int b = it[1];

            ll dis = multiply[a] - 1;

            if (dis > 0 && 1LL * b <= 2LL * mini) {
                mpp[b] += dis;
            }
        }

        ll ans = 0;

        ll remBudget = budget;

        for (auto &it : mpp) {
            int x = it.first;

            ll y = it.second;

            ll peak = min(y, remBudget / x);

            ans += peak * 2;
            remBudget -= peak * x;
        }

        if (mini > 0) {
            ans += remBudget / mini;
        }

        return (int)ans;
    }
};