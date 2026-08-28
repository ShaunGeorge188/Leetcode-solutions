class Solution {
public:
    int findNthDigit(int n) {
        long digitLength = 1;
        long count = 9;
        long start = 1;

        while(n > digitLength * count){
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        long number = start + (n - 1)/digitLength;
        int digitIndex = (n - 1) % digitLength;

        string numStr = to_string(number);
        return numStr[digitIndex] - '0';
    }
};