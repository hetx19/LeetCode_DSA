class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1 / x;
        }

        long long pow = labs(n); 

        long double ans = 1;

        while(pow != 0) {
            if((pow & 1) != 0) {
                ans *= x;
            }
            x *= x;
            pow = pow >> 1;
        }
        
        return ans;
    }
};