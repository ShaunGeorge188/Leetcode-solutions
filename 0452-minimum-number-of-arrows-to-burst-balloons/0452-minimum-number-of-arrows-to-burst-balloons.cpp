#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.empty()) return 0;

        // 1. Sort balloons by their end coordinate (xend) in ascending order
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int lastArrowPos = points[0][1];

        // 2. Iterate through balloons and shoot a new arrow whenever necessary
        for (size_t i = 1; i < points.size(); ++i) {
            // If the current balloon starts after our last arrow position, shoot a new arrow
            if (points[i][0] > lastArrowPos) {
                arrows++;
                lastArrowPos = points[i][1];
            }
        }

        return arrows;
    }
};