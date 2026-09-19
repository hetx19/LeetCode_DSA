class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1) {
            return arr;
        }

        int index = -1;

        for (int i = n - 1; i > 0; i--) {
            if (arr[i] < arr[i - 1]) {
                index = i - 1;
                break;
            }
        }

        if (index == -1) {
            return arr;
        }

        for (int i = n - 1; i > index; i--) {
            if (arr[i] < arr[index] && arr[i] != arr[i - 1]) {
                swap(arr[i], arr[index]);
                break;
            }
        }

        return arr;
    }
};