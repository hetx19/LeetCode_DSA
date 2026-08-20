class Solution {
private:
     int getMaxArea(vector<int> &histo) {
        int n = histo.size();
        stack<int> st;
        int maxArea = 0;

        for (int index = 0; index < n; index++) {
            while (!st.empty() && histo[st.top()] > histo[index]) {
                int element = histo[st.top()];
                st.pop();
                
                int nse = index, pse = (st.empty()) ? -1 : st.top();
                
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            
            st.push(index);
        }
        
        while (!st.empty()) {
            int nse = n;
            int element = histo[st.top()];
            st.pop();
            int pse = (st.empty()) ? -1 : st.top();
            
            maxArea = max(maxArea, element * (nse - pse - 1));
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> height(n, 0);

        for (auto &row : matrix) {
            for (int index = 0; index < n; index++) {
                if (row[index] == '1') {
                    height[index]++;
                } else {
                    height[index] = 0;
                }
            }

            int area = getMaxArea(height);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};