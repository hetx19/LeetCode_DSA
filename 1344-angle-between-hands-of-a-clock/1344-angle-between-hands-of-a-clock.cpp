class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourHand = (30 * ((hour % 12) + (minutes % 60) / 60.0));
        double minuteHand = (6 * minutes);

        return (hourHand > minuteHand) ? min(hourHand - minuteHand, 360 - hourHand + minuteHand) : min(minuteHand - hourHand, 360 - minuteHand + hourHand);
    }
};