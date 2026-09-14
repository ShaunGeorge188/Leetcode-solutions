#include <vector>
#include <algorithm>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        bool x_overlap = std::min(rec1[2], rec2[2]) > std::max(rec1[0], rec2[0]);
        bool y_overlap = std::min(rec1[3], rec2[3]) > std::max(rec1[1], rec2[1]);

        return x_overlap && y_overlap;
    }
};