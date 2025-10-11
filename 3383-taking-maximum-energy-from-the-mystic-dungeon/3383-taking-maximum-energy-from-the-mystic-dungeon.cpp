class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int maxEnergy = INT_MIN;

        for(int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + ((i + k < n) ? dp[i + k] : 0);
            maxEnergy = max(maxEnergy, dp[i]);
        }

        return maxEnergy;
    }
};