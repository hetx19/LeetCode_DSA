class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> ans(n, vector<int> (n));

       int left = 0, right = n - 1;
       int top = 0, bottom = n - 1;

       int num = 0;

       while(left <= right && top <= bottom) {
        // left to right
        for(int i = top; i <= bottom; i++) {
            ans[left][i] = ++num;
        }

        // top to bottom
        for(int i = left + 1; i <= bottom; i++) {
            ans[i][bottom] = ++num;
        }

        if(left < right && top < bottom) {
            // right to left
            for(int i = right - 1; i > left; i--) {
                ans[right][i] = ++num;
            }

            // bottom to top
            for(int i = right; i > left; i--) {
                ans[i][top] = ++num;
            }
        }

        left++;
        right--;
        top++;
        bottom--;
       }

       return ans;
    }
};