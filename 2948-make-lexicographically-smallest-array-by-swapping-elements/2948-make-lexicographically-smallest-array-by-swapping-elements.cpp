#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        std::vector<std::pair<int, int>> val_idx(n);
        
        for (int i = 0; i < n; ++i) {
            val_idx[i] = {nums[i], i};
        }
        
        // Sort by values to easily identify connected components
        std::sort(val_idx.begin(), val_idx.end());
        
        std::vector<int> res(n);
        int i = 0;
        
        while (i < n) {
            int j = i + 1;
            // Expand the current component as long as the gap is within the limit
            while (j < n && val_idx[j].first - val_idx[j-1].first <= limit) {
                j++;
            }
            
            // Collect and sort the original indices of this component
            std::vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(val_idx[k].second);
            }
            std::sort(indices.begin(), indices.end());
            
            // Place the sorted values back into the sorted original indices
            for (int k = 0; k < indices.size(); ++k) {
                res[indices[k]] = val_idx[i + k].first;
            }
            
            // Move to the next component
            i = j;
        }
        
        return res;
    }
};