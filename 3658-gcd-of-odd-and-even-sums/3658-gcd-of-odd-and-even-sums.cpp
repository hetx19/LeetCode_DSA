class Solution {
  private:
    int gcd(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }

        return a + b;
    }

  public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        int sumEven = (n * ((2 * n) + 1)) - sumOdd;

        return gcd(sumOdd, sumEven);
    }
};