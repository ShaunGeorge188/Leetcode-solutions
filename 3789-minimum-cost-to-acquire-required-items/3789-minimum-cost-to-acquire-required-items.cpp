
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long option1 = 1LL * need1 * cost1
                          + 1LL * need2 * cost2;

        int mn = min(need1, need2);
        int mx = max(need1, need2);

        long long option2 = 1LL * mn * costBoth
                          + 1LL * (need1 - mn) * cost1
                          + 1LL * (need2 - mn) * cost2;

        long long option3 = 1LL * mx * costBoth;

        return min({option1, option2, option3});
    }
};
