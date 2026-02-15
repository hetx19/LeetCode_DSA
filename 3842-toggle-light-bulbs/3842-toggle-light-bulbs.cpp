class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        vector<int> ans;
        map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[bulbs[i]]++;
        }

        for (auto it : mpp) {
            if ((it.second) & 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};