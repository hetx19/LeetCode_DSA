using ll = long long;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> result(n);
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        for (auto &it : mpp) {
            vector<int> &index = it.second;
            ll sum = 0;

            for (int &x : index) {
                sum += x;
            }
            
            ll leftSum = 0;
            int m = index.size();

            for(int i = 0; i < m; i++){
                ll rightSum = sum - leftSum - index[i];
                ll left  = 1LL * index[i] * i - leftSum;
                ll right = rightSum - 1LL * index[i] * (m - i - 1);

                result[index[i]] = left + right;

                leftSum += index[i];
            }
        }

        return result;
    }
};