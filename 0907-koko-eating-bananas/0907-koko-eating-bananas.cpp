class Solution {
public:
    int maxElement(vector<int>& arr) {
        int maxi = INT_MIN;

        for(int i = 0; i < arr.size(); i++) {
            maxi = max(arr[i], maxi);
        }

        return maxi;
    }

    long long int time(vector<int>& arr, int rate) {
        long long int time_hours = 0;

        for(int i = 0; i < arr.size(); i++) {
            time_hours += (arr[i] + rate - 1)/rate;
        }

        return time_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = maxElement(piles);

        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            long long int total_time = time(piles, mid);

            if(total_time <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};