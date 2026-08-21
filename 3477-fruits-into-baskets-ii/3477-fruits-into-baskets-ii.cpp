class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> isEmpty(n, true);
        int unplaced = 0;

        for (int &qty : fruits) {
            bool placed = false;

            for (int index = 0; index < n; index++) {
                if (isEmpty[index] && baskets[index] >= qty) {
                    isEmpty[index] = false;
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                unplaced++;
            }
        } 

        return unplaced;
    }
};