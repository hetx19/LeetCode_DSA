class Solution {
public:
    int minOperations(string s) {
        int start0 = 0, start1 = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i & 1) {
                if (s[i] == '1') {
                    start0++;
                } else {
                    start1++;
                }
            } else {
                if (s[i] == '1') {
                    start1++;
                } else {
                    start0++;
                }
            }
        }

        return min(start0, start1);
    }
};