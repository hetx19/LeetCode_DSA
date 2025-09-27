class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {
        int counter = 0, no_of_bouquet = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                counter++;
            } else {
                no_of_bouquet += (counter / k);
                counter = 0;
            }
        }
        
        no_of_bouquet += (counter / k);
        
        return no_of_bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int value = k * 1LL * m * 1LL;
        
        if (value > bloomDay.size()) {
            return -1;
        }
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi;
        
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            
            if(isPossible(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};