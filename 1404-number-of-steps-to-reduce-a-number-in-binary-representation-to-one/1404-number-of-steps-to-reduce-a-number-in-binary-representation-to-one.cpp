class Solution {
private:
    void divide(string& s) {
        s.pop_back();
    }

    void add(string& s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] != '0') {
            s[i] = '0';
            i--;
        }

        if (i < 0) {
            s = '1' + s;
        } else {
            s[i] = '1';
        }
    }

public:
    int numSteps(string s) {
        int n = s.size();

        int moves = 0;
        while (s.size() > 1) {
            if (s.back() == '0') {
                divide(s);
            } else {
                add(s);
            }
            moves++;
        }

        return moves;
    }
};