class Solution {
public:
    int smallestEvenMultiple(int n) {
        // If n is even, return n. Otherwise, return n * 2.
        return (n % 2 == 0) ? n : n * 2;
    }
};