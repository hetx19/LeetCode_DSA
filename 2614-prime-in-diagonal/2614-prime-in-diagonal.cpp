class Solution {
private:
    bool isPrime(int n) {
        if (n <= 2 || (n & 1) == 0) {
            return n == 2;
        }

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
    
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max({ans, isPrime(nums[i][i]) * nums[i][i], isPrime(nums[i][n - i - 1]) * nums[i][n - i - 1]});
        }

        return ans;
    }
};