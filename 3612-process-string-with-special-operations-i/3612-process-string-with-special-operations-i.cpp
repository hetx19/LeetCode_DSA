class Solution {
public:
    string processStr(string s) {
        string result = "";

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result += ch;
            } else if (ch == '#' && result.length() != 0) {
                result += result;
            } else if (ch == '*' && result.length() != 0) {
                result.pop_back();
            } else if (ch == '%' && result.length() != 0) {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};