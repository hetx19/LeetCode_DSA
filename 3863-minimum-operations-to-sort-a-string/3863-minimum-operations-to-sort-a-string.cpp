class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string sorted = s;
        
        sort(sorted.begin(), sorted.end());
        if (sorted == s) return 0;

        if(n == 2) return -1;
        
        int maxi = -1; int mini = 1000;
        for(char c : s){
            maxi = max(maxi, (int)c);
            mini = min(mini, (int)c);
        }

        if((int)s[0] == maxi && (int)s[n-1] == mini) {
            for(int i = 1; i < n - 1; i++) {
                if((int)s[i] == mini || (int)s[i] == maxi) {
                    return 2;
                }
            }
            return 3;
        }
        
        if((int)s[0] == mini || (int)s[n - 1] == maxi) {
            return 1;

        }
        
        return 2;
    }
    
};