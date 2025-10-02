class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int a = 1, b = (2 * numExchange) - 3, c = ((-2) * numBottles);
        double dis = (double)b * b - 4.0 * a * c;
        int t = (int)ceil((-b + sqrt(dis)) / (2.0 * a));
        return numBottles + t - 1;
    }
};