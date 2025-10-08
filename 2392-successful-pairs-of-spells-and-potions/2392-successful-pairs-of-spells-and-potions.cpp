class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size(), n = potions.size();
        vector<int> ans(m);

        // Sorting potions array
        sort(potions.begin(), potions.end());

        for(int i = 0; i < m; i++) {
            long long minPotionPower = (success + spells[i] - 1) / spells[i];
            int low = 0, high = n - 1;
            int firstOccurrence = n;

            while(low <= high) {
                int mid = low + ((high - low) >> 1);
            
                if ((long long) potions[mid] >= minPotionPower) {
                    firstOccurrence = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            int count = n - firstOccurrence;
            ans[i] = count;
        }

        return ans;
    }
};