class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans = {words[0]};
        int n = words.size();

        for(int i = 1; i < n; i++) {
            string a = words[i];
            string b = ans.back();
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if(a != b) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};