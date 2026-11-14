class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minLength = INT_MAX, startIndex = -1;

        int counter = 0;
        unordered_map<char, int> mpp;
        int left = 0;

        for (int i = 0; i < m; i++) {
            mpp[t[i]]++;
        }

        for (int right = 0; right < n; right++) {
            if (mpp[s[right]] > 0) {
                mpp[s[right]]--;
                counter++;

                while (counter == m) {
                    if (right - left + 1 < minLength) {
                        minLength = right - left + 1;
                        startIndex = left;
                    }

                    mpp[s[left]]++;
                    if (mpp[s[left]] > 0) {
                        counter--;
                    }
                    left++;
                }

            } else {
                mpp[s[right]]--;
            }
        }

        return (startIndex == -1) ? "" : s.substr(startIndex, minLength);
    }
};