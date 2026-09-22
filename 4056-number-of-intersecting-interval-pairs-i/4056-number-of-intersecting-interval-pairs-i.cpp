class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<>> pq;
        sort(intervals.begin(), intervals.end());

        pq.push(intervals[0][1]);

        int ans = 0;
        int n = intervals.size();

        for(int i = 1; i < n; i++) {
            while(!pq.empty() && pq.top() < intervals[i][0]) {
                pq.pop();
            }

            ans += pq.size();
            pq.push(intervals[i][1]);
        }

        return ans;
    }
};