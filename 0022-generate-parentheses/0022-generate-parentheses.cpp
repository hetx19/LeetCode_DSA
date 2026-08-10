class Solution {
private:
    void solve(int open, int close, int n, string current, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            solve(open + 1, close, n, current + "(", result);
        }

        if (close < open) {
            solve(open, close + 1, n, current + ")", result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);

        return ans;
    }
};