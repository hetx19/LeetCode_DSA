class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size(), n = potions.size();
        vector<int> ans(m);

        // Sorting potions array
        sort(potions.begin(), potions.end());
        int index = 0;

        for(int spell : spells) {
            long long minPotionPower = (success + spell - 1) / spell;
            int low = 0, high = n - 1;
            auto firstOccurrence = lower_bound(potions.begin(), potions.end(), minPotionPower);

            int count = n - static_cast<int>(firstOccurrence - potions.begin());
            ans[index++] = count;
        }

        return ans;
    }
};