class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> freq(26);

        for (int i = 0; i < n; i++) {
            fill(freq.begin(), freq.end(), 0);
            for (int j = i; j < n; j++) {
                bool flag = true;
                int ch = s[j] - 'a';
                freq[ch]++;

                for (auto x : freq) {
                    if (x > 0 && x != freq[ch]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};