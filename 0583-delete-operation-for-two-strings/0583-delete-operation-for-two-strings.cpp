class Solution {
private:
    int lcs(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<int> prev(n2 + 1, 0), current(n2 + 1, 0);

        for (int index1 = 1; index1 <= n1; index1++) {
            for (int index2 = 1; index2 <= n2; index2++) {
                if (word1[index1 - 1] == word2[index2 - 1]) {
                    current[index2] = 1 + prev[index2 - 1];
                } else {
                    current[index2] = max(prev[index2], current[index2 - 1]);
                }
            }
            prev = current;
        }

        return prev[n2];
    }

public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int lenghtOfLcs = lcs(word1, word2);
        
        return (n1 + n2 - (2 * lenghtOfLcs));
    }
};