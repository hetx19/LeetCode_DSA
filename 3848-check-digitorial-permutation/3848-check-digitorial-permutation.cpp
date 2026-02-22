class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> digitorials = {1, 2, 145, 40585};

        string s = to_string(n);
        sort(s.begin(), s.end());

        for (int num : digitorials) {
            if((int)to_string(num).size() != (int)s.size()) {
                continue;
            }
            string test = to_string(num);
            sort(test.begin(), test.end());

            if (s == test) {
                return true;
            }
        }
        return false;
    }
};