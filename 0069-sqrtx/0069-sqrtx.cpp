class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        
        int low = 1, high = x;
        int ans = 1;
        
        while(low <= high) {
            long long int mid = low + ((high - low) >> 1);
            long long int sq_value = mid * mid;
            
            if(sq_value <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};