class Solution {
  private:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }

  public:
    bool consecutiveSetBits(int n) {
        return isPowerOfTwo(n & (n >> 1));
    }
};