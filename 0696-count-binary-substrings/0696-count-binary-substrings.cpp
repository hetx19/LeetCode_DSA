class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, current = 1;
        int n = s.size();

        for (int i = 1; i < n; i++) {
            if (s[i - 1] != s[i]) {
                ans += min(prev, current);
                prev = current;
                current = 1;
            } else {
                current++;
            }
        }


        return ans + min(current, prev);
    }
};