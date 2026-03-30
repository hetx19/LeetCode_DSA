class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();

        int evenXOR = 0, OddXOR = 0, evenSq = 0, oddSq = 0;
        
        for (int i = 0; i < n; ++i) {
            int v1 = s1[i], v2 = s2[i];
            int diffXOR = v1 ^ v2;
            int diffSq = (v1 * v1) - (v2 * v2);
            if (i & 1) {
                OddXOR ^= diffXOR;
                oddSq += diffSq;
            } else {
                evenXOR ^= diffXOR;
                evenSq += diffSq;
            }
        }
        return !(evenXOR | OddXOR | evenSq | oddSq);
    }
};