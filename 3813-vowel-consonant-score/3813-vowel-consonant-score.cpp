class Solution {
private:
    bool isVowel(char ch) {
        if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u')) {
            return true;
        }
        return false;
    }

public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;

        for (char ch : s) {
            if (ch < 'a' || ch > 'z') {
                continue;
            }
            if (isVowel(ch)) {
                v++;
            } else {
                c++;
            }
        }

        if (c == 0) {
            return 0;
        }

        return v / c;
    }
};