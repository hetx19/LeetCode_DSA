class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int number = 1;

        for (int num : target) {
            while (number < num) {
                ans.push_back("Push");
                ans.push_back("Pop");
                number++;
            }
            number++;
            
            ans.push_back("Push");
        }

        return ans;
    }
};