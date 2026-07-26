class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi = -1000, sMaxi = -1000, tMaxi = -1000;
        int mini = 0, sMini = 0;

        for (int &num : nums) {
            if (maxi <= num){
                tMaxi = sMaxi;
                sMaxi = maxi;
                maxi = num;
            } else if (sMaxi <= num) {
                tMaxi = sMaxi;
                sMaxi = num;
            } else if (tMaxi <= num) {
                tMaxi = num;
            }

            if (mini >= num) {
                sMini = mini;
                mini = num;
            } else if (sMini >= num) {
                sMini = num;
            }
        }

        return max(maxi * sMaxi * tMaxi, mini * sMini * maxi);
    }
};