class Solution {
public:
    bool checkDivisibility(int n) {

        int remNum = n;

        int sum = 0;

        int prod = 1;

        while(remNum > 0){
            int currNum = remNum % 10;

            sum += currNum;

            prod *= currNum;

            remNum /= 10;
        }

        if( n % (sum + prod) == 0){
            return true;
        }else{
            return false;
        }
        
    }
};