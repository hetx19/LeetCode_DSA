class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        
        if (n == 1) {
            return ((k == 0) ? 1 : 0);
        }

        int total = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                total++;
            }
        }

        if (s[n - 1] == s[0]) {
            total++;
        }

        if (k == total) {
            return (n - total);
        }

        if (k == total - 1) {
            return total;
        }

        return 0;
    }
};