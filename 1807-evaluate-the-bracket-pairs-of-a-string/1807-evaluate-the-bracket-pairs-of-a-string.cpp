class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;

        for (auto& know : knowledge) {
            mpp[know[0]] = know[1];
        }

        string ans;
        int n = s.size();

        for (int index = 0; index < n; index++) {
            if (s[index] == '(') {
                int i = s.find(")", index + 1);
                string t = s.substr(index + 1, i - index - 1);
                ans += mpp.count(t) ? mpp[t] : "?";
                index = i;
            } else {
                ans += s[index];
            }
        }

        return ans;
    }
};