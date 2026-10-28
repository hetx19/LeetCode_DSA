class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;

        if (n >= 1){
            isPrime[1] = false;
        }

        for (int i = 2; i * i <= n + 1; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n + 1; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> result;
        int sum = 0;

        for (int i = 2; i <= n; i++) {
            if (!isPrime[i]) {
                continue;
            }

            if (sum + i > s) {
                break;
            }
            sum += i;

            result.push_back(i);
        }

        return result;
    }
};