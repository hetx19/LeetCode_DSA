class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int &num : nums) {
            arr.push_back(to_string(num));
        }

        sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        if (arr[0] == "0") {
            return "0";
        }

        int totalLength = 0;
        for (string &s : arr) {
            totalLength += s.size();
        }

        string ans;
        for (string &s : arr) {
            ans += s;
        }

        return ans;
    }
};