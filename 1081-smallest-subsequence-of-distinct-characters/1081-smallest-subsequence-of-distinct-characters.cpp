class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> visited(26), number(26);

        for (char ch : s) {
            number[ch - 'a']++;
        }

        string st;

        for (char ch : s) {
            if (!visited[ch - 'a']) {
                while (!st.empty() && st.back() > ch) {
                    if (number[st.back() - 'a'] > 0) {
                        visited[st.back() - 'a'] = 0;
                        st.pop_back();
                    } else {
                        break;
                    }
                }

                visited[ch - 'a'] = 1;
                st.push_back(ch);
            }

            number[ch - 'a'] -= 1;
        }

        return st;
    }
};