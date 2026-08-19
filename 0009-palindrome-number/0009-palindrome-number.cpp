class Solution {
public:
    bool isPalindrome(int x) {
        int c = x;
        if(x < 0) return false;
        int r;
        long long s = 0;
        while(x != 0){
            r = x % 10;
            s = s * 10 + r;
            x /= 10;
        }

        if(c == s){
            return true;
        }else{
            return false;
        }
    }
};