class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2, 0);
        int counter = 0;

        unordered_map<int, int> mp;

        //Pre calculation
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for(auto it : mp) {
            if(it.second == 2) {
                ans[counter++] = it.first;
            }
        }

        return ans;
    }
};