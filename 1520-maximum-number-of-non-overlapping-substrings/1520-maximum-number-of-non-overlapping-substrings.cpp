class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        
        vector<int> firstOccurrence(26, INT_MAX);
        vector<int> lastOccurrence(26, INT_MIN);

        for (int i = 0; i < n; i++) {
            firstOccurrence[s[i] - 'a'] = min(firstOccurrence[s[i] - 'a'], i);
            lastOccurrence[s[i] - 'a'] = max(lastOccurrence[s[i] - 'a'], i);
        }
        
        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i++) {
            if (firstOccurrence[i] < n) {
                int start = firstOccurrence[i];
                int end = lastOccurrence[i];
                for (int j = start; j <= end; j++) {
                    start = min(start, firstOccurrence[s[j] - 'a']);
                    end = max(end, lastOccurrence[s[j] - 'a']);
                }
                if (start == firstOccurrence[i]) {
                    intervals.push_back({end, start});
                }
            }
        }
        
        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int lastSelectedEnd = -1;

        for (auto &[end, start] : intervals) {
            if (start > lastSelectedEnd) {
                ans.push_back(s.substr(start, end - start + 1));
                lastSelectedEnd = end;
            }
        }
        
        return ans;
    }
};