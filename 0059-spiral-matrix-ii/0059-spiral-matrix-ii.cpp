class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> ans(n, vector<int> (n));

       int left = 0, right = n - 1;
       int top = 0, bottom = n - 1;

       int num = 0;

       while(left <= right && top <= bottom) {
        // left to right
        for(int i = left; i <= right; i++) {
            ans[top][i] = ++num;
        }
        top++;

        // top to bottom
        for(int i = top; i <= bottom; i++) {
            ans[i][right] = ++num;
        }
        right--;

        if(top <= bottom) {
            // right to left
            for(int i = right; i >= left; i--) {
                ans[bottom][i] = ++num;
            }
            bottom--;
        }

        if(left <= right) {
            // bottom to top
            for(int i = bottom; i >= top; i--) {
                ans[i][left] = ++num;
            }
            left++;
        }
       }

       return ans;
    }
};