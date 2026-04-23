class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        vector<double> angle;

        int s1 = sides[0], s2 = sides[1], s3 = sides[2];
        if (s1 + s2 <= s3) {
            return angle;
        }

        angle.resize(3);

        angle[0] = acos((pow(s1, 2) + pow(s2, 2) - pow(s3, 2)) / (2.0 * s1 * s2));
        angle[1] = acos((pow(s1, 2) + pow(s3, 2) - pow(s2, 2)) / (2.0 * s1 * s3));
        angle[2] = acos((pow(s3, 2) + pow(s2, 2) - pow(s1, 2)) / (2.0 * s3 * s2));

        for (double &ang : angle) {
            ang = ang * 180.0 / M_PI;
        }

        sort(angle.begin(), angle.end());

        return angle;
    }
};