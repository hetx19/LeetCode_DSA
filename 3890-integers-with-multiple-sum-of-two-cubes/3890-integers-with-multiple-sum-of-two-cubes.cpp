using ll = long long;

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        int limit = cbrt(n);

        for (ll i = 1; i <= limit; i++) {
            ll iCube = i * i * i;

            for (ll j = i; j <= limit; j++) {
                ll sum = iCube + j * j * j;

                if (sum > n) {
                    break;
                }

                mpp[sum]++;
            }
        }

        for (auto &it : mpp) {
            if (it.second >= 2) {
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};