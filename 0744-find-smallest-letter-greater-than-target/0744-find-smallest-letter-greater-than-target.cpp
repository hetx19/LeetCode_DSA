class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        int low = 0, high = letters.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (letters[mid] <= target) {
                low = mid + 1;
            } else {
                ans = letters[mid];
                high = mid - 1;
            }
        }

        return ans;
    }
};