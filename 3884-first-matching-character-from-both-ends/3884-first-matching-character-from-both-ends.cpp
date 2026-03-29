class Solution {
public:
    int firstMatchingIndex(string s) {
        int low = 0, high = s.size() - 1;

        while (low <= high) {
            if (s[low] == s[high]) {
                return low;
            } else {
                low++;
                high--;
            }
        }

        return -1;
    }
};