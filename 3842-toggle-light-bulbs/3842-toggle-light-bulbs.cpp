class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        vector<bool> isON(101, false);

        for (int i = 0; i < n; i++) {
            isON[bulbs[i]] = !isON[bulbs[i]];
        }

        vector<int> ans;
        for (int i = 0; i < 101; i++) {
            if (isON[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};