class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n <= 1) {
            return s;
        }

        vector<bool> dp(n, false);

        int start = 0;
        int maxLength = 1;

        for (int index = n - 1; index >= 0; index--) {
            for (int prev = n - 1; prev >= index; prev--) {
                if (s[index] == s[prev] && (prev - index <= 2 || dp[prev - 1])) {
                    dp[prev] = true;
                    
                    if (prev - index + 1 > maxLength) {
                        start = index;
                        maxLength = prev - index + 1;
                    }
                } else {
                    dp[prev] = false;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
