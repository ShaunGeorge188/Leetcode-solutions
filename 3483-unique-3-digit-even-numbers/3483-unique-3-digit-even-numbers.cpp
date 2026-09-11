class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for(int d: digits) freq[d]++;

        int count = 0;

        for(int num = 100; num <= 998; num+=2){
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            int need[10] = {0};
            need[d1]++;
            need[d2]++;
            need[d3]++;

            bool ok = true;
            for(int i = 0; i < 10; i++){
                if(need[i] > freq[i]){
                    ok = false;
                    break;
                }
            }

            if (ok) count++;
        }

        return count;
    }
};