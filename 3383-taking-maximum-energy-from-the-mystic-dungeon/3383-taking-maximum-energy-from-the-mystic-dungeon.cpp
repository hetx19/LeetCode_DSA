class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxEnergy = INT_MIN;
        int n = energy.size();

        for(int i = n - k; i < n; i++) {
            int totalEnergy = 0;
            for (int j = i; j >= 0; j -= k) {
                totalEnergy += energy[j];
                maxEnergy = max(maxEnergy, totalEnergy);
            }
        }

        return maxEnergy;
    }
};