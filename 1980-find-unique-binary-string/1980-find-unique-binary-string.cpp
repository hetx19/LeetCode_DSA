class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> Inte;
        for (string num : nums) {
            Inte.insert(stoi(num, 0 , 2));
        }

        int n = nums.size();
        for (int i = 0; i<= n; i++) {
            if (Inte.find(i) == Inte.end()) {
                string ans = bitset<16>(i).to_string();
                return ans.substr(16 - n);
            }
        }

        return "";
    }
};