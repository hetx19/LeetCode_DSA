using ll = long long;

class Solution {
private:
    ll processStr(string s) {
        ll result = 0;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result += 1;
            } else if (ch == '#') {
                result *= 2;
            } else if (ch == '*') {
                result = result + ((result > 0) ? -1 : 0);
            }
        }

        return result;
    }

public:
    char processStr(string s, long long k) {
        ll finalLength = processStr(s);

        if (k >= finalLength) return '.';

        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if (ch == '*') {
                finalLength++;
            } else if (ch == '#') {
                ll half = finalLength / 2;

                if (k >= half) {
                    k -= half;
                }

                finalLength = half;
            } else if (ch == '%') {
                k = finalLength - k - 1;
            } else {
                if (k == finalLength - 1) {
                    return ch;
                }
                finalLength--;
            }
        }

        return '.';
    }
};