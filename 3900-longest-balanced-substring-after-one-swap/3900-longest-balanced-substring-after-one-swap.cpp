class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int, vector<int>> mpp;
        mpp[0].push_back(-1);

        int zero = 0, one = 0;
        for (char &ch : s) {
            if (ch == '0') zero++;
            else one++;
        }

        int length = 0, maxLength = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') length++;
            if (s[i] == '0') length--;

            if (mpp.find(length) != mpp.end()) {
                maxLength = max(maxLength, i - mpp[length][0]);
            }

            if(mpp.find(length - 2) != mpp.end()) {
                for(int j : mpp[length - 2]){
                    int len = i - j;
                    int usedZeros = (len - 2) >> 1;
                    if(zero > usedZeros){
                        maxLength = max(maxLength, len);
                        break;
                    }
                }
            }

            if(mpp.find(length + 2) != mpp.end()) {
                for(int j : mpp[length + 2]){
                    int len = i - j;
                    int usedOnes = (len - 2) >> 1;
                    if(one > usedOnes){
                        maxLength = max(maxLength, len);
                        break;
                    }
                }
            }

            mpp[length].push_back(i);
        }

        return maxLength;
    }
};