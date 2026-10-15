#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        // Iterate over all possible starting points of subarrays
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinct_elements;
            
            // Expand the subarray from the starting point i to the end
            for (int j = i; j < n; ++j) {
                distinct_elements.insert(nums[j]);
                
                // The size of the set gives the distinct count for nums[i..j]
                int count = distinct_elements.size();
                total_sum += count * count;
            }
        }
        
        return total_sum;
    }
};