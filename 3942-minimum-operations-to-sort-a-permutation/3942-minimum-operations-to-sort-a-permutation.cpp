class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back(i);
        }

        if (temp == nums) {
            return 0;
        }

        reverse(temp.begin(), temp.end());

        if(temp == nums) {
            return 1;
        }

        int l1 = 1,l2 = 0;
        int i = 1;
        bool isIncreasing = false;

        if (nums[1] == (nums[0] + 1)) {
            isIncreasing = true;

            while (i < n && nums[i] == nums[i - 1] + 1) {
                l1++;
                i++;
            }
        } else if(nums[1] == (nums[0] - 1)) {
            isIncreasing = false;

            while(i < n && nums[i] == (nums[i - 1] - 1)) {
                l1++;
                i++;
            }
        } else {
            if (nums[2] > nums[1]) {
                isIncreasing = true;
            } else {
                isIncreasing = false;
            }
        }

        l2++;
        i++;

        if (isIncreasing) {
            while (i < n && nums[i] == (nums[i - 1] + 1)) {
                isIncreasing=true;
                l2++;
                i++;
            }
        } else {
            while(i < n && nums[i] == (nums[i - 1] - 1)) {
                isIncreasing = false;
                l2++;
                i++;
            }
        }

        if((l1 + l2) != n) {
            return -1;
        }

        int op = INT_MAX;

        if (isIncreasing) {
            op = min(op, l1);
            op = min(op, l2 + 2);
        } else {
            op = min(op, l1 + 1);
            op = min(op, l2 + 1);
        }

        return op;
    }
};