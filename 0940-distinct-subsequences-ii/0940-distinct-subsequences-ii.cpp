#include <string>
#include <vector>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        int MOD = 1e9 + 7;
        
        // Track the number of distinct subsequences ending with each character
        std::vector<int> ends(26, 0);
        int total = 0;
        
        for (char c : s) {
            int old_ends = ends[c - 'a'];
            
            // The new number of subsequences ending in `c`
            ends[c - 'a'] = (total + 1) % MOD;
            
            // Update the running total of all distinct subsequences
            // We add MOD before subtracting to avoid negative numbers in modulo arithmetic
            total = ((total + ends[c - 'a']) % MOD - old_ends + MOD) % MOD;
        }
        
        return total;
    }
};