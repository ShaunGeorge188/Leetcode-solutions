class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> reservedByrow;

        for(auto& r : reservedSeats){
            int row = r[0];
            int seats = r[1];

            if(seats < 2 || seats > 9) continue;

            if(reservedByrow.find(row) == reservedByrow.end()){
                reservedByrow[row] = vector<bool>(10, false);  
            }
            reservedByrow[row][seats] = true;
        } 

        int totalFamilies = 0;

        for(auto& [row, seats] : reservedByrow){
            bool leftFree = !seats[2] && !seats[3] && !seats[4] && !seats[5];
            bool middleFree = !seats[4] && !seats[5] && !seats[6] && !seats[7];
            bool rightFree = !seats[6] && !seats[7] && !seats[8] &&!seats[9];

            if(leftFree && rightFree){
                totalFamilies += 2;
            }else if(leftFree || middleFree || rightFree){
                totalFamilies += 1;
            }
        }
        int untouchedRows = n - reservedByrow.size();
        totalFamilies += untouchedRows * 2;

        return totalFamilies;
    }

    
};