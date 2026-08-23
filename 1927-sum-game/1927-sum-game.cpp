#include <string>
#include <cmath>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.size();
        int sumL = 0, cntL = 0;
        int sumR = 0, cntR = 0;

        // Count sums and '?' for both halves
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') cntL++;
            else sumL += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') cntR++;
            else sumR += num[i] - '0';
        }

        int diff = sumL - sumR;
        int qDiff = cntL - cntR;

        // If total net '?' count is odd, Alice can always force a win
        if (qDiff % 2 != 0) {
            return true;
        }

        // Bob wins if he can perfectly balance the sum difference with pairs of '?'
        return diff + (qDiff / 2) * 9 != 0;
    }
};