class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int numberOfBars = 0;

        for (int cost : costs) {
            if (coins >= cost) {
                numberOfBars++;
                coins -= cost;
            }
        }

        return numberOfBars;
    }
};