#include <cmath>
#include <algorithm>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Calculate the minute hand angle (6 degrees per minute)
        double minute_angle = minutes * 6.0;
        
        // Calculate the hour hand angle
        // (hour % 12) converts 12 to 0 so we don't start at 360 degrees
        double hour_angle = (hour % 12) * 30.0 + (minutes * 0.5);
        
        // Find the absolute difference between the two angles
        double diff = std::abs(hour_angle - minute_angle);
        
        // We want the smaller angle, so it must be <= 180 degrees
        return std::min(diff, 360.0 - diff);
    }
};