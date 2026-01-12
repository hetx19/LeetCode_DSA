class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size(), ans = 0; 
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(s[i]);
            if (st.size() == (i + 1) % 3) {
                ans++;
            }
            if (st.size() >= 3) return ans;
        }

        return ans;
    }
};