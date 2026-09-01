class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // bill == 20
                // Greedily prefer giving one $10 and one $5 as change
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                // Fallback to giving three $5 bills if no $10 is available
                else if (five >= 3) {
                    five -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};