class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size(), ans = 0; 
        unordered_set<char> st;

        for (int i = 0; i < n; i++) {
            st.insert(s[i]);
            if (st.size() >= 3) {
                break;
            }
            if (st.size() == (i + 1) % 3) {
                ans++;
            }
        }

        return ans;
    }
};