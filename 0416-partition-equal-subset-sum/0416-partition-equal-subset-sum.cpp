class Solution {
private:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<bool> prev(sum + 1, false), current(sum + 1, false);

        prev[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = true;

        for (int index = 1; index < n; index++) {
            current.assign(sum + 1, false);
            current[0] = true;

            for (int target = 1; target <= sum; target++) {
                bool notTake = prev[target];
                bool take = false;

                if (arr[index] <= target)
                    take = prev[target - arr[index]];

                current[target] = take || notTake;
            }

            prev = current;
        }

        return prev[sum];
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) {
            return false;
        }

        return isSubsetSum(nums, sum / 2);
    }
};