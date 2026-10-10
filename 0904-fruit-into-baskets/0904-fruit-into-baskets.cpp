class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0, left = 0;

        unordered_map<int, int> mpp;

        for (int right = 0; right < n; right++) {
            mpp[fruits[right]]++;

            if (mpp.size() > 2) {
                while (mpp.size() > 2) {
                    mpp[fruits[left]]--;

                    if (mpp[fruits[left]] == 0) {
                        mpp.erase(fruits[left]);
                    }

                    left++;
                }
            }

            if (mpp.size() <= 2) {
                maxFruits = max(maxFruits, right - left + 1);
            }
        }

        return maxFruits;
    }
};