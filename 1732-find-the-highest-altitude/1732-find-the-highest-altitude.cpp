class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0, altitude = 0;

        for (int &diff : gain) {
            altitude += diff;
            maxAltitude = max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};