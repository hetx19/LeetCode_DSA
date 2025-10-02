class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int bottleReturn = 0;

        while(numBottles >= numExchange) {
            int newBottles = numBottles / numExchange;
            ans += newBottles;
            bottleReturn = numBottles % numExchange;
            numBottles = newBottles + bottleReturn;
        }

        return ans;
    }
};