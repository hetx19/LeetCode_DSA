class Solution {
  private:
    int solve(vector<int>& arr, int target, int index, vector<vector<int>>& dp) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0) {
                return 2;
            }
            
            if (target == 0 || arr[0] == target) {
                return 1;
            }
            
            return 0;
        }

        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        int notPick = solve(arr, target, index - 1, dp);
        int pick = (arr[index] <= target) ? solve(arr, target - arr[index], index - 1, dp) : 0;

        return dp[index][target] = (pick + notPick);
    }

    int perfectSum(vector<int>& arr, int target) {
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(target + 1, -1));
		return solve(arr, target, n - 1, dp);
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