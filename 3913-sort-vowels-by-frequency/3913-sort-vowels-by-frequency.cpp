class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        unordered_map<char, int> firstPos;

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                freq[s[i]]++;
                if (!firstPos.count(s[i])) {
                    firstPos[s[i]] = i;
                }
            }
        }

        vector<char> vowels;
        for (auto &it : freq) {
            vowels.push_back(it.first);
        }

        sort(vowels.begin(), vowels.end(), [&](char a, char b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            }
            return firstPos[a] < firstPos[b];
        });

        vector<char> ordered;
        for (char ch : vowels) {
            for (int i = 0; i < freq[ch]; i++) {
                ordered.push_back(ch);
            }
        }

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = ordered[j++];
            }
        }

        return s;
    }
};