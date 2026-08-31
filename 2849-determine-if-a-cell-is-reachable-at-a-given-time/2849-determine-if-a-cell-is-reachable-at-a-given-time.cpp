#include <algorithm>
#include <cmath>

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // Calculate the minimum steps required using Chebyshev distance
        int min_time = std::max(std::abs(sx - fx), std::abs(sy - fy));
        
        // Edge case: Start and target are the same cell
        if (min_time == 0) {
            return t != 1;
        }
        
        // As long as we have at least the minimum time, we can reach it
        return t >= min_time;
    }
};