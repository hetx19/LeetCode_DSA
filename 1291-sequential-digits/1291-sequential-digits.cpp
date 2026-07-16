class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int i = 1; i < 10; i++) {
            int num = i;
            for (int j = i + 1; j < 10; j++) {
                num = num * 10 + j;
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};