class Solution {
private:
    bool isPalindrome(string s, int start, int end) {
        int left = start, right = end;

        while (left <= right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }

        return true;
    }

    void solve(string s, int n, int index, vector<string>& ds, vector<vector<string>>& ans) {
        if (index == n) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < n; i++) {
            if (isPalindrome(s, index, i)) {
                ds.push_back(s.substr(index, i - index + 1));

                solve(s, n, i + 1, ds, ans);

                ds.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> ds;

        solve(s, n, 0, ds, ans);

        return ans;
    }
};