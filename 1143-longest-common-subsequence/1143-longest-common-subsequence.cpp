class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> prev(n2 + 1, 0), current(n2 + 1, 0);

        for (int index1 = 0; index1 <= n1; index1++) {
            prev[0] = 0;
        }

        for (int index1 = 1; index1 <= n1; index1++) {
            for (int index2 = 1; index2 <= n2; index2++) {
                if (text1[index1 - 1] == text2[index2 - 1]) {
                    current[index2] = 1 + prev[index2 - 1];
                } else {
                    current[index2] = max(prev[index2], current[index2 - 1]);
                }
            }
            prev = current;
        }

        return prev[n2];
    }
};