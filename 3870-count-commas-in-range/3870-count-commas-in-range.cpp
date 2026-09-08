class Solution {
public:
    int countCommas(int n) {
        if(n < 1000){
            return 0;
        }
        int res;

        if(1000 <= n <= 100000){
            res = n - (1000 - 1);
        }
        
        return res;
    }
};