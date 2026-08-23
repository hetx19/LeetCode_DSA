class Solution {
private:
    bool checkPalindrome(string s) {
        int low = 0, high = s.size() - 1;

        while (low < high) {
            if (s[low] == s[high]) {
                low++;
                high--;
            } else {
                return false;
            }
        }

        return true;
    }

public:
    bool isPalindromic(string s) {
        string binary = "";

        for (char ch : s) {
            int ascii = int(ch);

            string bin = bitset<8>(ascii).to_string();

            binary += bin;
        }

        return checkPalindrome(binary);
    }
};