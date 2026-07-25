class Solution {
public:
    int canMake(int n, vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        int bouq = 0;

        for(int bloom : bloomDay){
            if(bloom <= day){
                count++;
                if(count == k){
                    bouq++;
                    count = 0;
                }
            }else{
                count = 0;
            }
        }
        return bouq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long) m * k > n) return -1;

        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());


        while(min < max){
            int mid = (min + max) / 2;

            if(canMake(n, bloomDay, mid, m, k) >= m){
                max = mid;
            }else{
                min = mid + 1;
            }
        }
        return min;
    }
};