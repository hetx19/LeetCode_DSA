class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> mpp;
        long long cnt = 0;

        for (string word : words) {
            int m = word.size();
            string normalized(m, 'a');
            int shift = word[0] - 'a';

            for (int i = 0; i < m; i++) {
                normalized[i] = 'a' + (word[i] - 'a' - shift + 26) % 26;
            }

            cnt += mpp[normalized];
            mpp[normalized]++;
        }

        return cnt;
    }
};