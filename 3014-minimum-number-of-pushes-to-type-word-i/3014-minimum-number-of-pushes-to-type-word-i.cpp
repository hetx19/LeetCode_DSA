class Solution {
public:
    int minimumPushes(string word) {
        int fullGroups = word.size() >> 3, remainingChars = word.size() & 7;

        return ((fullGroups << 2) + remainingChars) * (fullGroups + 1);
    }
};