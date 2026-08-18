class Solution {
private:
    static bool comparator(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        return n1 < n2;
    }

    bool compare(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        if (n1 - n2 != 1) {
            return false;
        }

        int ptr1 = 0, ptr2 = 0;

        while (ptr1 < n1) {
            if (word1[ptr1] == word2[ptr2]) {
                ptr1++;
                ptr2++;
            } else {
                ptr1++;
            }
        }

        return (ptr1 == n1 && ptr2 == n2);
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int index = 0; index < n; index++) {
            for (int prev = 0; prev < index; prev++) {
                if (compare(words[index], words[prev]) && dp[index] < 1 + dp[prev]) {
                    dp[index] = 1 + dp[prev];
                }
            }

            maxi = max(dp[index], maxi);
        }

        return maxi;
    }
};