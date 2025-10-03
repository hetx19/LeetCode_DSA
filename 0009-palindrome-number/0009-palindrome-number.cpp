class Solution {
public:
    bool isPalindrome(int x) {
        int dup = x;
        int ans = 0;

        while(dup > 0) {
            int digit = dup%10;
            if(ans > INT_MAX/10) {
                return false;
            }
            ans = (ans*10) + digit;
            dup = dup / 10;
        }

        if(ans == x) return true;
        return false;
    }
};