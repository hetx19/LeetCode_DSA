class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxi = INT_MIN;

        while (left < right) {
            int l = right - left;
            int b = min(height[right], height[left]);

            int area = l * b;
            maxi = max(maxi, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxi;
    }
};