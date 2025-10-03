class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        for(int i = 0;  i < nums.size() - 2; i++) {
            if(i > 0 && arr[i] == arr[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;

            while(j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum > 0) {
                    k--;
                } else if(sum < 0) {
                    j++;
                } else {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.emplace_back(temp);

                    // Skip duplicates for j and k
                    int leftVal = arr[j], rightVal = arr[k];

				    while(j < k && arr[j] == leftVal) {
                        j++;
                    }
                    while(j < k && arr[k] == rightVal) {
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};