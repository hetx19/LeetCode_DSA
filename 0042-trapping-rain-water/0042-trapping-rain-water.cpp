class Solution {
public:
    int trap(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int left = height[low], right = height[high];
        int water = 0;

        while(low < high) {
            if(left < right) {
                left = max(left, height[++low]);
                water += left - height[low];
            } else {
                right = max(right, height[--high]);
                water += right - height[high];
            }
        }

        return water;
    }
};