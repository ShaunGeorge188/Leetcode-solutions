#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Helper function to calculate the sum of digits of a number
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    // Structure to hold the element's data for custom sorting
    struct Element {
        int val;
        int sum;
        int orig_idx;
        
        // Custom comparator for sorting
        bool operator<(const Element& other) const {
            if (sum != other.sum) return sum < other.sum;
            return val < other.val;
        }
    };

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<Element> arr(n);
        
        // Populate the array with values, digit sums, and original indices
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], getDigitSum(nums[i]), i};
        }
        
        // Sort based on the custom comparator
        sort(arr.begin(), arr.end());
        
        // Array to keep track of visited elements to detect cycles
        vector<bool> visited(n, false);
        int swaps = 0;
        
        // Find cycles and calculate required swaps
        for (int i = 0; i < n; i++) {
            // If the element is already in the correct place or visited, skip
            if (visited[i] || arr[i].orig_idx == i) {
                continue;
            }
            
            int cycle_size = 0;
            int j = i;
            
            // Traverse the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].orig_idx;
                cycle_size++;
            }
            
            // A cycle of size L requires L - 1 swaps
            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};