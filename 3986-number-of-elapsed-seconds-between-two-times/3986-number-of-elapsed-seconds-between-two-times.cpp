class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hour1 = stoi(startTime.substr(0, 2));
        int minute1 = stoi(startTime.substr(3, 2));
        int second1 = stoi(startTime.substr(6, 2));

        int hour2 = stoi(endTime.substr(0, 2));
        int minute2 = stoi(endTime.substr(3, 2));
        int second2 = stoi(endTime.substr(6, 2));

        return (hour2 - hour1) * 3600 + (minute2 - minute1) * 60 + (second2 - second1);
    }
};