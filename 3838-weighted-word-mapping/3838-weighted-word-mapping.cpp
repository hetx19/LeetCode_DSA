class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (string &word : words) {
            int wordWeight = 0;

            for (char &ch : word) {
                wordWeight += weights[ch - 'a'] % 26;
            }

            ans.push_back('z' - (wordWeight % 26));
        }

        return ans;
    }
};