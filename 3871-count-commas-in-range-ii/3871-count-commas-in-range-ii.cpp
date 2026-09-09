class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long threshold = 1000;

        while(n >= threshold){
            res += (n - threshold + 1);
            threshold *= 1000;
        }
        return res;
    }
};