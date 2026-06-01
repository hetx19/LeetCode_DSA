class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size(), total = 0;
        sort(cost.begin(), cost.end());

        for (int i = n - 1; i >= 0; i -= 3) {
            total += cost[i];
            total += ((i > 0) ? cost[i - 1] : 0);
        }

        return total;
    }
};