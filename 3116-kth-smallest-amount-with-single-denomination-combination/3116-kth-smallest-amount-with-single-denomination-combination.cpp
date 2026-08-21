#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        
        // Helper function to count valid amounts <= X
        auto count = [&](long long X) -> long long {
            long long total = 0;
            // Iterate through all 2^n - 1 non-empty subsets
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int bits = 0;
                
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        bits++;
                        current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                    }
                }
                
                // Inclusion-Exclusion: Add for odd subsets, subtract for even
                if (bits % 2 == 1) {
                    total += X / current_lcm;
                } else {
                    total -= X / current_lcm;
                }
            }
            return total;
        };

        // Binary search bounds
        long long min_coin = *std::min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};