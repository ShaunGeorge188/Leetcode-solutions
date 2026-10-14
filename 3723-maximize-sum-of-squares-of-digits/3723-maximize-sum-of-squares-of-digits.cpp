class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        int nines = sum / 9;
        int rem = sum % 9;

        string res(nines, '9');
        if (rem > 0) res += char('0' + rem);
        res += string(num - res.size(), '0');

        return res;
    }
};