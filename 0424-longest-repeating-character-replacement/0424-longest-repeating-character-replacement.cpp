class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLength = 0, maxFreq = 0;
        int left = 0;
        unordered_map<char, int> mpp;
        
        for (int right = 0; right < n; right++) {
            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);

            if ((right - left + 1) - maxFreq > k) {
                mpp[s[left]]--;
                left++;
            }

            if (right - left + 1 - maxFreq <= k) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        return maxLength;
    }
};