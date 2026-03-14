class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, lastOne = -1;

        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1)) {
                if (lastOne >= 0) {
                    ans = max(ans, i - lastOne);
                }
                lastOne = i;
            }
        }

        return ans;
    }
};