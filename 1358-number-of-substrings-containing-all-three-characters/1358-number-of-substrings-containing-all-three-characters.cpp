class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> lastSeen(3, -1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                ans += (min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1);
            }
        }

        return ans;
    }
};