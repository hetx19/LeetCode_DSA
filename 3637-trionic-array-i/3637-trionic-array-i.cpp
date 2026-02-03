class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(); 
        int i = 1;
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        int j = i - 1;
        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        int k = i - 1;
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        int flag = i - 1;
        return (j != 0) && (k != j) && (flag == n - 1 && flag != k);
    }
};