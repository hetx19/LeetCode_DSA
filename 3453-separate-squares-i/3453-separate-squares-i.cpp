class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxY = 0, totalArea = 0;
        for (auto& sq : squares) {
            int y = sq[1], l = sq[2];
            totalArea += (double)l * l;
            maxY = max(maxY, (double)(y + l));
        }

        auto ch = [&](double limitY) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                int y = sq[1], l = sq[2];
                if (y < limitY) {
                    area += l * min(limitY - y, (double)l);
                }
            }
            return area >= totalArea / 2;
        };

        double low = 0, high = maxY;

        while (abs(high - low) > 1e-5) {
            double mid = (high + low) / 2;

            if (ch(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }
};