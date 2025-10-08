class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size(), m = spells.size();
        vector<int> ans(m);

        // Sorting potions array
        sort(potions.begin(), potions.end());

        for (int i = 0; i < m; i++) {
            long long spell_pow = spells[i];
            long long minPotionPower = (success + spell_pow - 1) / spell_pow;
            auto it = lower_bound(potions.begin(), potions.end(), minPotionPower);
            ans[i] = n - static_cast<int>(it - potions.begin());
        }
        return ans;
    }
};