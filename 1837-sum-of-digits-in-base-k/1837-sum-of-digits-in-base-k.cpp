class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;

        while (n > 0) {
            int digit = n % k;   // get the last digit in base k
            sum += digit;        // add it to our running sum
            n /= k;               // remove that digit from n
        }

        return sum;
    }
};