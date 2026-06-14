class Solution {
private:
    pair<long long, long long> calculateSum(int n) {
        long long digitSum = 0, squareSum = 0;

        while (n != 0) {
            int digit = n % 10;
            digitSum += 1LL * digit;
            squareSum += 1LL * (digit * digit);
            n /= 10;
        }

        return {digitSum, squareSum};
    }

public:
    bool checkGoodInteger(int n) {
        pair<long long, long long> ans = calculateSum(n);
        return (ans.second - ans.first) >= 50;
    }
};