class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int hour = 0; hour < 12; hour++) {
            for (int min = 0; min < 60; min++) {
                int cnt = __builtin_popcount(hour) + __builtin_popcount(min);

                if (cnt == turnedOn) {
                    string time = to_string(hour) + ":";

                    if (min < 10) {
                        time += "0";
                    }

                    time += to_string(min);

                    ans.push_back(time);
                }
            }
        }

        return ans;
    }
};