class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[5] = {0};
        string s = "balon";

        for (char ch : text) {
            for (int i = 0; i < 5; i++) {
                freq[i] += !(ch ^ s[i]);
            }
        }

        return min({freq[0], freq[1], freq[2] >> 1, freq[3] >> 1, freq[4]});
    }
};