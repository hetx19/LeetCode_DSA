class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        for (int i = 1; i < n - 1; i++) {
            for (int j = 0; j < n - i; j++) {
                s[j] = ((s[j] - '0') + (s[j + 1] - '0')) % 10 + '0';
            }
        }
        
        return s[0] == s[1];
    }
};