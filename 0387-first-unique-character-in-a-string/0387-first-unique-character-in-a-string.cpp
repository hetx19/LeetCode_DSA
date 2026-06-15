class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;

        for (char &ch : s) {
            mpp[ch]++;
        }

        for (int i = 0; i < n; i++) {
            if (mpp[s[i]] == 1) {
                return i;
            }            
        }

        return -1;
    }
};