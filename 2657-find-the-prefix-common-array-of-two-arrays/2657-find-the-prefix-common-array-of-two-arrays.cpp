class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);

        unordered_set<int> elementsInA, elementsInB;

        for (int i = 0; i < n; i++) {
            elementsInA.insert(A[i]);
            elementsInB.insert(B[i]);

            int commonCnt = 0;

            for (auto &ele : elementsInA) {
                if (elementsInB.count(ele)) {
                    commonCnt++;
                }
            }

            ans[i] = commonCnt;
        }

        return ans;
    }
};