class Solution {
  private:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0), current(target + 1, 0);

        prev[0] = (arr[0] == 0) ? 2 : 1;

        if (arr[0] != 0 && arr[0] <= target) {
            prev[arr[0]] = 1;
        }

        for (int index = 1; index < n; index++) {
            for (int t = 0; t <= target; t++) {
                int notPick = prev[t];

                int pick = 0;
                if (arr[index] <= t) {
                    pick = prev[t - arr[index]];
                }

                current[t] = pick + notPick;
            }
            prev = current;
        }

        return prev[target];
    }
    
    int countPartitions(vector<int>& arr, int diff) {
	    int totalSum = accumulate(arr.begin(), arr.end(), 0);
	    
	    if (totalSum - diff < 0 || (totalSum - diff) & 1 != 0) {
	        return 0;
	    }
	    
	    return perfectSum(arr, (totalSum - diff) / 2);
    }
    
  public:
	int findTargetSumWays(vector<int>& nums, int target) {
		return countPartitions(nums, target);
	}
};