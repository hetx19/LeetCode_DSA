class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> frequency(10, 0);

        for (int &d : digits) {
            frequency[d]++;
        }

        int count = 0;

        for (int first = 1; first < 10; first++){
            if (frequency[first] == 0) {
                continue;
            }

            frequency[first]--;

            for (int mid = 0; mid < 10; mid++){
                if (frequency[mid] == 0) {
                    continue;
                }

                frequency[mid]--;
                
                for (int last = 0; last < 10; last += 2){
                    if (frequency[last] > 0) {
                        count++;
                    }
                }

                frequency[mid]++;
            }

            frequency[first]++;
        }

        return count;
    }
};