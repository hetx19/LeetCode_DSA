class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        unordered_map<char, int> mpp;

        int left = 0, right = 0;

        while (right < n) {
            if (mpp.find(s[right]) != mpp.end()) {
                if (mpp[s[right]] >= left) {
                    left = mpp[s[right]] + 1;
                }
            }

            int length = right - left + 1;
            maxLength = max(maxLength, length);
            mpp[s[right]] = right;
            right++;
        }

        return maxLength;
    }
};