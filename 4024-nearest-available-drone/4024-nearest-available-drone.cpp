class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int minDistance = INT_MAX;
        int index = -1;
        
        for (int i = 0 ; i < n; i++) {
            int distance = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);

            if (distance <= drones[i][2] && distance < minDistance) {
                minDistance = distance;
                index = i;
            }
        }
        
        return index;
    }
};