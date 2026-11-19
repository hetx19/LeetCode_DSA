class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0, right = 0;
        while (left < m && right < n) {
            if (g[right] <= s[left]) {
                right++;
            }

            left++;
        }

        return right;
    }
};