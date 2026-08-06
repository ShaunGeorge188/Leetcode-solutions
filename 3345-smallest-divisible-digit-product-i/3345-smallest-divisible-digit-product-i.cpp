class Solution {
public:
    int calcProd(int x){
        int p = 1;
        while(x > 0){
            p *= (x % 10);
            x /= 10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        int x = n;
        while(calcProd(x) % t != 0) x++;
        return x;
    }
};