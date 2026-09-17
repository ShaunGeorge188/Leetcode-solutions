#include <vector>
#include <algorithm>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        std::vector<int> min_len(n, INF);

        int l = 0;
        int current_sum = 0;
        int min_combined_length = INF;
        int best_single_len = INF;

        for (int r = 0; r < n; ++r) {
            current_sum += arr[r];

            // Shrink window if sum exceeds target
            while (current_sum > target && l <= r) {
                current_sum -= arr[l];
                l++;
            }

            // Found a valid sub-array ending at 'r' with start at 'l'
            if (current_sum == target) {
                int curr_len = r - l + 1;

                // Check if there is a valid non-overlapping sub-array before index 'l'
                if (l > 0 && min_len[l - 1] != INF) {
                    min_combined_length = std::min(min_combined_length, curr_len + min_len[l - 1]);
                }

                best_single_len = std::min(best_single_len, curr_len);
            }

            // min_len[r] tracks the shortest sub-array ending at or before 'r'
            min_len[r] = best_single_len;
        }

        return min_combined_length == INF ? -1 : min_combined_length;
    }
};