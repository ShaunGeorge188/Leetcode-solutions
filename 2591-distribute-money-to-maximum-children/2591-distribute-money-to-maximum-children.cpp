class Solution {
public:
    int distMoney(int money, int children) {
        // Rule 1: Everyone must receive at least 1 dollar.
        money -= children;
        if (money < 0) return -1;
        
        int count7 = money / 7;
        int remaining = money % 7;
        
        // Edge Case 1: Exact fit where everyone gets 8 and 0 money is left over
        if (count7 == children && remaining == 0) {
            return count7;
        }
        
        // Edge Case 2: The forbidden $4 trap
        if (count7 == children - 1 && remaining == 3) {
            return count7 - 1;
        }
        
        // Edge Case 3: We have excess money or count7 exceeds children capacity. 
        // We must cap it at children - 1 because someone has to absorb the extra money.
        if (count7 >= children) {
            return children - 1;
        }
        
        return count7;
    }
};