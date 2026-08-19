class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // map: row number -> which seats are reserved (only seats 2..9 matter)
        unordered_map<int, vector<bool>> reservedByRow;

        for (auto& r : reservedSeats) {
            int row = r[0];
            int seat = r[1];
            if (seat < 2 || seat > 9) continue; // seat 1 and 10 never matter

            // create the row's seat array (index 2..9) the first time we see it
            if (reservedByRow.find(row) == reservedByRow.end()) {
                reservedByRow[row] = vector<bool>(10, false); // index 0..9, we only use 2..9
            }
            reservedByRow[row][seat] = true;
        }

        int totalFamilies = 0;

        // rows that have at least one reservation in seats 2..9
        for (auto& [row, seats] : reservedByRow) {
            bool leftFree   = !seats[2] && !seats[3] && !seats[4] && !seats[5];
            bool middleFree = !seats[4] && !seats[5] && !seats[6] && !seats[7];
            bool rightFree  = !seats[6] && !seats[7] && !seats[8] && !seats[9];

            if (leftFree && rightFree) {
                // both outer blocks free, they don't overlap, so we can fit both
                totalFamilies += 2;
            } else if (leftFree || middleFree || rightFree) {
                // at least one block is free, fit one family
                totalFamilies += 1;
            }
            // else: no valid block in this row, add 0
        }

        // rows with no reservations at all: each can fit exactly 2 families
        int untouchedRows = n - reservedByRow.size();
        totalFamilies += untouchedRows * 2;

        return totalFamilies;
    }
};