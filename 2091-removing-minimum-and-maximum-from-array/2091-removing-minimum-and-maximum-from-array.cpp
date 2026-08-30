#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        int min_idx = 0;
        int max_idx = 0;
        
        // Find the indices of the minimum and maximum elements
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) min_idx = i;
            if (nums[i] > nums[max_idx]) max_idx = i;
        }
        
        // Order the indices so we know which is closer to the front and back
        int left = std::min(min_idx, max_idx);
        int right = std::max(min_idx, max_idx);
        
        // Strategy 1: Delete everything from the front up to the rightmost target
        int remove_front = right + 1;
        
        // Strategy 2: Delete everything from the back down to the leftmost target
        int remove_back = n - left;
        
        // Strategy 3: Delete from the front to 'left', and from the back to 'right'
        int remove_both_sides = (left + 1) + (n - right);
        
        return std::min({remove_front, remove_back, remove_both_sides});
    }
};